#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
 
const ll INF = 1LL<<62;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;
typedef priority_queue<int, vector<int>, greater<int>> PQ;
const int MOD = 1000000007;

const int max_a = 20005;

int main(){
    int N,K; cin >> N >> K;
    int R, S, P; cin >> R >> S >> P;
    //rep(i,3) cin >> RSP[i];
    string T; cin >> T;
    vector<bool> win(N, false);

    ll ans = 0;
    rep(i, T.size()){
        int prev_index = i - K;
        if (prev_index >= 0 && T[i] == T[prev_index] && win[prev_index]) continue;
        if(T[i] == 'r'){
            ans+=P;
        }
        else if(T[i] == 's'){
            ans+=R;
        }
        else{
            ans+=S;
        }
        win[i] = true;
    }    

    cout << ans << endl;
}
