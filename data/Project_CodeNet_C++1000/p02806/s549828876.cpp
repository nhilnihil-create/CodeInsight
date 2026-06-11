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
    ll n,cnt=0;
    cin>>n;
    vector<string> s(n);
    vector<ll> t(n);
    rep(i,n) cin>>s[i]>>t[i];
    string x; cin>>x;
    for(int i=n-1;i>=0;i--){
        if(s[i]==x) break;
        cnt+=t[i];
    }
    cout<<cnt<<endl;
    return 0;
}