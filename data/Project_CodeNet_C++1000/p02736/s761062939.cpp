#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define ll long long
using namespace std;
//typedef vector<unsigned int>vec;
//typedef vector<ll>vec;
//typedef vector<vec> mat;
typedef pair<int, int> P;
typedef pair<ll,ll> LP;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const int INF = 1000000000;
const ll LINF = 1000000000000000000;//1e18
const ll  MOD = 1000000007;
const double PI = acos(-1.0);
const double EPS = 1e-10;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
//template<class T> inline void add(T &a, T b){a = ((a+b) % MOD + MOD) % MOD;};


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    string S;
    cin >> N >> S;
    vector<int> a(N), b(N-1);
    bool one = false;
    REP(i,N){
        a[i] = S[i] - '0';
        if(i > 0){
            b[i-1] = abs(a[i] - a[i-1]);
            if(b[i-1] & 1) one = true;
        }
    }
    if(!one) REP(i, N-1) b[i] /= 2;
    
    int ans = 0;
    REP(i,N-1){
        // _(n-2)C_i
        if(b[i] == 1 && ((N-2) & i) == i) ans ^= 1;
    }
    if(!one) ans *= 2;
    cout << ans << endl;
}
