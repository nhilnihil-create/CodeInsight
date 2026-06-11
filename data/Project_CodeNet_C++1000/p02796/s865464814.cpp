#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <cmath>
#include <limits>
#define ALL(x) (x).begin(),(x).end()
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define int_INF 2147483647
#define pint_INF 2000000000
#define ll_INF 	9223372036854775807
#define MOD 1000000007
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
#define vvc vector<vector<char>>
#define vll vector<long long>
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
#define sysp system("PAUSE")
#define pno cout << "no" << endl
#define pyes cout << "yes" << endl
#define pYes cout << "Yes" << endl
#define pNo cout << "No" << endl
using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;
    vvi vec(N, vi(2));

    for (int i = 0; i < N; i++) {
        int x, s; cin >> x >> s;
        vec[i][0] = x - s;
        vec[i][1] = x + s;
    }
    sort(ALL(vec));

    vi left(N), right(N);
    rep(i, N) {
        left[i] = vec[i][0];
        right[i] = vec[i][1];
    }

    vi dp(N + 1);
    dp[N] = 0;
    //dp[N-1] = 1;
    for (int i = N - 1; i >= 0; i--) {
        auto iter = lower_bound(ALL(left), right[i]);

        int j = distance(left.begin(), iter);

        dp[i] = max(dp[i + 1], dp[j] + 1);
    }

    cout << dp[0] << endl;
}