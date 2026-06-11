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
    int N,L;
    cin >> N >> L;
    int hoge = 10000,ans = 0;
    bool aa = false;
    for (int i = 1; i <= N; i++) {
        int a = L + i - 1;
        ans += a;
        if (hoge > abs(a)) {
            hoge = abs(a);
            if (a < 0) aa = false;
            else aa = true;
        }
    }
    cout << ans - (aa ? 1 : -1) * hoge << endl;
    return 0;
}