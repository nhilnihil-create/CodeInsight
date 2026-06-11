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

int main(){

    int N; cin >> N;
    vector<int> L(N);
    rep(i,N) cin >> L[i];
    sort(L.begin(), L.end());

    int ans = 0;
    for (int i = 0; i < N; i++){
        for (int j = i + 1; j < N; j++){
            int ab = L[i] + L[j];
            int ng = N;
            int ok = -1;
            while(abs(ok-ng)>1){
                int mid = (ok+ng) / 2;
                if (L[mid] < ab) ok = mid;
                else ng = mid;
            }
            int count = ok - j;
            if (count > 0) ans += count;
        }
    }
    cout << ans << endl;

}