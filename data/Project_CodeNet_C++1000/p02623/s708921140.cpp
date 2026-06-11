#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using ll = long long;
#define int ll
using ld = long double;
using vi = vector<int>;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
constexpr int INF = 0x3f3f3f3f; constexpr ll LLINF = 0x3f3f3f3f3f3f3f3f;
#define db(x) { cerr << #x << " = " << x << endl; }
template <typename T> void _dbarr(T* a, size_t sz){ for(int i = 0; i < sz; i++) cerr << a[i] << " \n"[i == sz-1]; }
template <typename T> void _dbarr(vector<T> a, size_t sz){ for(int i = 0; i < sz; i++) cerr << a[i] << " \n"[i == sz-1]; }
#define dbarr(x, n) {cerr << #x << ": "; _dbarr((x),(n));}
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back
#define mpr make_pair
#define fs first
#define sn second

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	//freopen("in.txt","r", stdin);
    int n,m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n), b(m); for(ll& v : a) cin >> v; for(ll& v : b) cin >> v;
    vector<ll> psaa(n), psab(m);
    ll cur = 0;
    for(int i = 0; i < n; i++){
        cur += a[i];
        psaa[i] = (i == 0 ? 0 : psaa[i-1]) + a[i];
    }
    cur = 0;
    for(int i = 0; i < m; i++){
        cur += b[i];
        psab[i] = (i == 0 ? 0 : psab[i-1]) + b[i];
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        // fix A
        int diff = k-psaa[i];
        if(diff < 0) continue;
        if(diff == 0){ ans = max(ans,i+1); continue; }
        //cerr << "current diff: " << diff << "\n";
        //cerr << "psa: " << psaa[i] << "\n";
        auto itr = upper_bound(psab.rbegin(), psab.rend(), diff,
                       [](ll a, ll b){return a>=b;});
        if(itr == psab.rend()){
            ans = max(ans,i+1);
        }else{
            //cerr << "found: " << *itr << " " << distance(psab.begin(),itr.base()) << "\n";
            ans = max(ans,(i+1)+(int)distance(psab.begin(),itr.base()));
        }
    }
    for(int i = 0; i < m; i++){
        // fix B
        int diff = k-psab[i];
        if(diff < 0) continue;
        if(diff == 0){ ans = max(ans,i+1); continue; }
        //cerr << "current diff: " << diff << "\n";
        //cerr << "psa: " << psaa[i] << "\n";
        auto itr = upper_bound(psaa.rbegin(), psaa.rend(), diff,
                       [](ll a, ll b){return a>=b;});
        if(itr == psaa.rend()){
            ans = max(ans,i+1);
        }else{
            //cerr << "found: " << *itr << " " << distance(psab.begin(),itr.base()) << "\n";
            ans = max(ans,(i+1)+(int)distance(psaa.begin(),itr.base()));
        }
    }
    cout << ans << "\n";
}
