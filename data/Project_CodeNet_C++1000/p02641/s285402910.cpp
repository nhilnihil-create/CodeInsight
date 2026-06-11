//Compiler optimization
#pragma GCC optimize("Ofast")

//include
#include <bits/stdc++.h>
using namespace std;

//typedef
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<char> vc;
typedef string S;
typedef queue<int> qi;
typedef pair<ll,ll> P;
typedef vector<P> vp;
typedef vector<vl> mat;

//macro
#define reverse(a) reverse(a.begin(),a.end())
#define unique(a) a.erase(unique(a.begin(),a.end()),a.end())
#define fr(i,n)for(ll i=0;i<(n);i++)
#define ifr(i,n)for(ll i=(n)-1;i>=0;i--)
#define all(x) x.begin(),x.end()
#define each(x, v) for (auto &x : v)

//abbreviation
#define pb push_back
#define elif else if
#define mp make_pair
#define endl '\n'

//debug
#define debug(x) cerr << #x << ": " << x << endl
#define v_debug(v) cerr << #v << endl;fr(i,v.size()) cerr << i << ": " << v[i] << endl

//const
const  ll INF = 1e18;


int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << setprecision(20);
    ll x,n; cin >> x >> n;
    vl data(110);
    fr(i,n){
        ll p;cin >> p;
        data[p]++;
    }
    ll ans = 0;
    ll now = 100000;
    for(int i = -300;i <= 300;i++){
        if(i >= 1 && i <=100 && data[i])continue;
        if(abs(ans- x) > abs(i - x)){
            ans = i;
        }
    }
    cout << ans << endl;
}