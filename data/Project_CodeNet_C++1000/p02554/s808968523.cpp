#include<bits/stdc++.h>
using namespace std;


int main(){
    long long int n;
    cin>>n;
    long long int nin=1,eig=1,ten=1;
    long long int mod=1e9+7;
    for(int i=0; i<n; i++){
        nin=(nin*9)%mod;
        eig=(eig*8)%mod;
        ten=(ten*10)%mod;
    }
    long long int ans = (ten+eig)%mod -(2*nin)%mod;
    cout<<(ans+mod)%mod<<endl;
}