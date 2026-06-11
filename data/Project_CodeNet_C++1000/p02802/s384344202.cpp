#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(long long i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

int main(void)
{
    ll n, m, AC=0, WA=0;
    cin >> n >> m;
    vector<ll> ac(n,0), wa(n,0);
    rep(i,m){
        ll a; string s;
        cin>>a>>s;
        a--;
        if(ac[a]) continue;
        if(s=="AC"){
            ac[a]=1;
        }else{
            wa[a]++;
        }
    }
    rep(i,n){
        AC += ac[i];
        if(ac[i]) WA += wa[i];
    }
    cout << AC << " " << WA << endl;
    return 0;
}