#include <bits/stdc++.h>
using namespace std;
///////////////////////////////////////////
const long long int INF = 1LL<<60;
const long long int Mod = 1000000007;
using ll = long long int; using ci = const int;
using vi = vector<int>;  using Vi = vector<long long int>;
using P = pair<int, int>;  using PLL = pair<ll, ll>;
using matrix = vector<vector<ll>>;
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define rp(i,N) for(ll i = 0; i < (ll)N; i++)
#define repi(i,a,b) for(ll i = ll(a); i < ll(b); ++i)
template<class T>bool chmax(T &former, const T &b) { if (former<b) { former=b; return true; } return false; }
template<class T>bool chmin(T &former, const T &b) { if (b<former) { former=b; return true; } return false; }
template<class T>T sqar(T x){ return x*x; }//sqrt(x)は平方根;
#define Sort(v) std::sort(v.begin(), v.end(), std::greater<decltype(v[0])>()) //降順でVをソート
#define p_queue(v) priority_queue<v, vector<v>, greater<v> >
template<class T> inline void princ(T x){cout<<x<<" ";}; 
template<class T> inline void print(T x){cout<<x<<"\n";};
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
///////////////////////////////////////////////////////////////////////////////////

const ll MAX = 5000001;//10^7が限界
const ll MOD = Mod;
//const ll MOD = INT64_MAX;
ll fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (ll i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
ll COM(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

void solve(){
    ll n,k;
    cin >> n >> k;
    matrix mat(n);
    rp(i,n-1){
        ll a,b;
        cin >> a >> b;
        a--;
        b--;
        mat[a].pb(b);
        mat[b].pb(a);
    }
    COMinit();
    queue<ll> que;
    vi seen(n,0);
    ll ans=k;
    if(k-1-mat[0].size()<0){
        print(0);
        return;
    }
    ans*=COM(k-1,mat[0].size())*fac[(int)mat[0].size()]%Mod;
    ans%=Mod;
    repi(i,1,n){
        if(k-1-mat[i].size()<0){
            print(0);
            return;
        }
        ans*=COM(k-2,mat[i].size()-1)*fac[mat[i].size()-1]%Mod;
        ans%=Mod;
    }
    /*seen[0]=1;
    for(auto l:mat[0]){
        que.push(l);
    }
    while(!que.empty()){
        ll nod=que.front(); que.pop();
        if(seen[nod]==1) continue;
        seen[nod]=1;
        if(k-1-mat[nod].size()<0){
            print(0);
            return;
        }
        ans*=fac[k-2]*finv[k-mat[nod].size()-1]%Mod;
        ans%=Mod;
        for(auto l:mat[nod]){
            if(seen[l]==0)
            que.push(l);
        }
    }*/
    ans%=Mod;
    print(ans);
    return;
}
int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    std::cout<<std::fixed<<std::setprecision(30);
    solve();
    return 0;
}