#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = (n-1); i >= 0; i--)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const ll INF = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;

int main(){

    int N; cin >> N;
    vector<int> X(N);
    rep(i,N) cin >> X[i];

    sort(X.begin(), X.end());

    int sum = 0;
    rep(i,N){
        sum += X[i];
    }

    int ans = 100000000;
    for(int i = 0; i <= 100; i++){
        int tmp = 0;
        rep(j,N){
            tmp += (X[j]-i)*(X[j]-i);
        }
        ans = min(ans,tmp);
    }
    cout << ans << endl;
}

    