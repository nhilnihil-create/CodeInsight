#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

const int MOD = 1e9+7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,k,a=0;
    cin>>n>>k;
    for (int i=k; i<=n+1; ++i){
        a += (n-i+1)*i + 1;
        a%=MOD;
    }
    cout<<a;
    return 0;
}