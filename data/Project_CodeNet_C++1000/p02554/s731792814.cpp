#include<iostream>

using namespace std;
typedef long long ll;

const int MOD = 1e9+7;

ll modPow(ll a,ll b){
    ll res = 1;

    while(b){
        if(b&1){
            res = (res*a)%MOD;
        }
        a = (a*a)%MOD;
        b >>= 1;
    }
    return res;
}

ll solve(ll n){
   return ((modPow(10,n)+modPow(8,n)-2*modPow(9,n))%MOD+MOD)%MOD;
}

int main()
{
    ll n;
    cin>>n;
    
    cout<<solve(n)<<endl;
    return 0;
}