#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);
//const ll mod = 998244353;

ll lcm(ll a, ll b){
    return a / __gcd(a, b) * b;
}

int main(void)
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), s, ord(n+1,-1);
    rep(i,n) cin >> a[i];
    ll c = 1, l = 0;
    {
        ll v = 1; //1スタートなのでordのサイズはn+1
        while(ord[v] == -1){ //未訪問なら続行
            ord[v] = s.size();
            s.push_back(v);
            v = a[v-1];
        }
        c = s.size() - ord[v];
        l = ord[v];
    }
    if(k < l) cout << s[k] << endl;
    else{
        k -= l;
        k %= c;
        cout << s[l+k] << endl;
    }
    return 0;
}