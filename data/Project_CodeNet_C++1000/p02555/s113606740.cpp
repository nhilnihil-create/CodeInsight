#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
#define rep(i, s, e) for (int i = s; i < e; i++)
#define endl '\n'
int main()
{
    const ll MOD= 1000000007;
    ll s;
    cin >> s;
    ll x[s+10];
    x[0]=1;
    for(ll i=1;i<s+1;i++){
        if(i<3){
            x[i]=0;
        }else{
            x[i]=(x[i-3]+x[i-1])%MOD;
        }
    }


    cout << x[s] << endl;
}