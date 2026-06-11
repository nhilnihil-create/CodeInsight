#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<int, int> P;
vector<ll> res;
const long long MAX_V = 3234566667;

void dfs(ll num) {
    if (num > MAX_V) return ;
    res.push_back(num);
    int be = num % 10;
    int a1 = be - 1, a2 = be + 1;
    if (a1 >= 0) dfs(num * 10 + a1);
    if (a2 <= 9) dfs(num * 10 + a2);
    dfs(num * 10 + be);
    return ;
}

int main()
{
    int K;
    cin >> K;

    repd(i, 1, 10) {
        dfs(i);
    }

    sort(all(res));

    cout << res[K - 1] << endl;
    return 0;
}