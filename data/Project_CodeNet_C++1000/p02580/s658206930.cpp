#include <bits/stdc++.h>
using namespace std;

// 型定義
typedef long long ll;
typedef pair<ll, ll> P;

// forループ
#define REP(i,n) for(ll i=0; i<(ll)(n); ++i)

// 定数宣言
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

// グラフ表現
using Graph = vector<vector<int>>;

// グラフの辺表現
using Edge = map<pair<int,int>,int>;

// n次元配列の初期化。第２引数の型のサイズごとに初期化していく。
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

// 最大公約数
ll gcd(ll a,ll b){
   if (a%b == 0) return(b);
   else return(gcd(b, a%b));
}

// 最小公倍数
ll lcm(ll a, ll b){
    return a/gcd(a, b) * b;
}

int main()
{
    cout << fixed << setprecision(15);
    ll H, W, M;
    cin >> H >> W >> M;

    vector<ll> Mh(M);
    vector<ll> Mw(M);

    vector<ll> h(H+1, 0);
    vector<ll> w(W+1, 0);

    REP(i, M){
        ll x;
        ll y;

        cin >> x >> y;

        Mh[i] = x;
        Mw[i] = y;
        
        h[x]++;
        w[y]++;
    }

    vector<ll> hq(H+1);
    vector<ll> wq(W+1);

    REP(i, H+1){
        hq.push_back(h[i]);
    }
    REP(i, W+1){
        wq.push_back(w[i]);
    }

    sort(hq.rbegin(), hq.rend());
    sort(wq.rbegin(), wq.rend());

    ll now = hq[0];
    ll hcount = 0;

    REP(i, H){
        if(hq[i] == now) hcount++;
        else break;
    }

    now = wq[0];
    ll wcount = 0;

    REP(i, W){
        if(wq[i] == now) wcount++;
        else break;
    }
    
    ll maxcount = hcount * wcount;
    ll ans = hq[0] + wq[0];

    ll temp_count = 0;
    REP(i, M){
        if(h[Mh[i]] + w[Mw[i]] == ans) temp_count++;
    }

    if(temp_count < maxcount){
        cout << ans << endl;
    }
    else{
        cout << ans-1 << endl;
    }
    return 0;
}