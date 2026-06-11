#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int>nn(n);
    for(int i=0;i<n;i++)nn[i] = i+1;
    int p[n];
    int q[n];
    for(int i=0;i<n;i++)cin >> p[i];
    for(int i=0;i<n;i++)cin >> q[i];

    int a = -1;
    int b = -1;

    int cnt = 0;
    
    do{
        cnt++;
        if(a==-1){
            bool chk = true;
            for(int i=0;i<n;i++){
                if(nn[i] != p[i]){
                    chk = false;
                    break;
                }
            }
            if(chk){
                a = cnt;
            }
        }

        if(b==-1){
            bool chk = true;
            for(int i=0;i<n;i++){
                if(nn[i] != q[i]){
                    chk = false;
                    break;
                }
            }
            if(chk){
                b = cnt;
            }
        }
    }while(next_permutation(nn.begin(),nn.end()));

    cout << abs(a-b)<<endl;
}