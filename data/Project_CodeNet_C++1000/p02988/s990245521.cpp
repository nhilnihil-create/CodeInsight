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
    int N,ans = 0;
    cin >> N;
    vector<int> p(N);
    rep(i,N) cin >> p.at(i);
    for (int i = 1; i < N - 1; i++) {
        if ((p.at(i) > p.at(i - 1) && p.at(i) < p.at(i + 1)) || (p.at(i) < p.at(i - 1) && p.at(i) > p.at(i + 1))) ans++;
    }
    cout << ans << endl;
    return 0;
}