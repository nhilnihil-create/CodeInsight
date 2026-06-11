#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,N) for(int i = 0; i < (N); i++)
#define erep(i,N) for(int i = N - 1; i >= 0; i--)
const ll INF = 1000000000;
const ll mod = 1000000007;
#define PI 3.1415926535
using Graph = vector<vector<int>>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true;} return false;}
typedef pair<int, int> pair;
bool seen[505][505];

//dpTable
//bool dp[100050];

int main(){
    int N;
    cin >> N;
    vector<int> W(N);
    rep (i,N) cin >> W.at(i);
    int ans = 1000000;
    for (int i = 0; i < N; i++) {
        int a = 0,b = 0;
        for (int j = 0; j < i; j++) {
            a += W.at(j);
        }
        for (int j = i; j < N; j++) {
            b += W.at(j);
        }
        ans = min(ans,abs(a - b));
    }
    cout << ans << endl;
    return 0;
}