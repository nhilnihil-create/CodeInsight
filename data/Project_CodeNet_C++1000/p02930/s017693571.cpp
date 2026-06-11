#include<bits/stdc++.h>
using namespace std;

int n;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=0;i+1<n;i++){
        for(int j=i+1;j<n;j++){
            int k=i^j,cnt=0;
            while(k){
                k>>=1;
                cnt++;
            }
            cout<<cnt<<' ';
        }
        cout<<endl;
    }

    return 0;
}