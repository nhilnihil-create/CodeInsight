#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<(n);++i)
#define rep2(i,a,b) for (ll i=(a);i<(b);++i)
#define debug(x) cout << #x << '=' << x << endl
#define all(v) (v).begin(),(v).end()
const ll MOD=1e9+7;
//const ll MOD=998244353;
const ll INF=1e9;
const ll IINF=1e18;
const double EPS=1e-8;
const double pi=acos(-1);

template<class T> inline bool chmin(T &a,T b){
    if (a>b){a=b; return true;} return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){a=b; return true;} return false;
}

const int MAX_ROW=61; // to be set appropriately
const int MAX_COL=1e5+10; // to be set appropriately

struct BitMatrix {
    int H, W;
    bitset<MAX_COL> val[MAX_ROW];
    BitMatrix(int m = 1, int n = 1) : H(m), W(n) {}
    inline bitset<MAX_COL>& operator [] (int i) {return val[i];}
};

void GaussJordan(BitMatrix &A, bool is_extended = false) {
    vector<bool> used(A.H, 0);
    for (int col = 0; col < A.W; ++col) {
        if (is_extended && col == A.W - 1) break;
        int pivot = -1;
        for (int row = 0; row < A.H; ++row) {
            if (used[row]) continue;
            if (A[row][col]) {
                pivot = row;
                break;
            }
        }
        if (pivot == -1) continue;
        for (int row = 0; row < A.H; ++row) {
            if (row != pivot && A[row][col]) A[row] ^= A[pivot];
        }
        used[pivot] = true;
    }
}

const int MAX_B=61;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];
    vector<int> cnt(MAX_B,0),can(MAX_B,0);
    ll ans=0;
    BitMatrix BM(MAX_B,N+1);
    for (int i=MAX_B-1;i>=0;--i){
        rep(j,N) if (A[j]&(1LL<<i)) ++cnt[i];
        if (cnt[i]&1) ans+=1LL<<i;
        else if (cnt[i]>0){
            can[i]=1;
            rep(j,N) if (A[j]&(1LL<<i)) BM[MAX_B-1-i][j]=1;
            BM[MAX_B-1-i][N]=1;
        }
    }
    GaussJordan(BM,true);
    rep(i,MAX_B){
        if (!can[MAX_B-1-i]) continue;
        int ok=0;
        rep(j,N) if (BM[i][j]==1) ok=1;
        if (BM[i][N]==0) ok=1;;
        if (ok) ans+=(2LL<<(MAX_B-1-i));
    }
    cout << ans << endl;
}