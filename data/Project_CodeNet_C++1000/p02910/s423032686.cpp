#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
 
int main(){
    string S;
    cin >> S;
    int N=S.size(),flag=0;
    
    for(int i=0; i<N; i++){
        if(i%2==0){
            if(S.at(i)=='R' || S.at(i)=='U' || S.at(i)=='D'){
                flag=0;
            }
            else{
                flag=1;
                break;
            }
        }
        if(i%2==1){
            if(S.at(i)=='L' || S.at(i)=='U' || S.at(i)=='D'){
                flag=0;
            }
            else{
                flag=1;
                break;
            }

        }

    }
    if(flag==1){
        cout << "No" << endl;
    }
    else{

     cout << "Yes" << endl;
    }
 
}