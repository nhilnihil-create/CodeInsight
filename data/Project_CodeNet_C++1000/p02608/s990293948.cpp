#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);


int main(void)
{
    ll n; cin>>n;
    vector<ll> s(10050,0);
    for(int i=1;i<=100;i++){
        for(int j=1;j<=100;j++){
            for(int k=1;k<=100;k++){
                ll x = i*i + j*j + k*k + i*j + j*k + k*i;
                if(x <= n) s[x]++;
            }
        }
    }
    rep(i,n) cout<<s[i+1]<<endl;
    return 0;
}