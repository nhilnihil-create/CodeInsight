#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const ll INF = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;
typedef priority_queue<int, vector<int>, greater<int>> PQ;

int main(){
    int N; cin >> N;
    vector<int> A(N), B(N);
    rep(i,N) cin >> A[i] >> B[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int ans;
    int min, max;
    if (N % 2 == 1){
        min = A[N/2];
        max = B[N/2];
    }
    else{
        min = A[N/2-1] + A[N/2];
        max = B[N/2-1] + B[N/2];
    }
    ans = max - min + 1;
    cout << ans << endl;
}