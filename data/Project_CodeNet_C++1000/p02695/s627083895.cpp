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
#include <list>
#include <cassert>
#include <functional>
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
#define pNO cout << "NO" << endl
#define pYES cout << "YES" << endl
#define endl "\n"
#define pi 3.14159265358979
using namespace std;
using ll = long long;

int main() {
    int N, M, Q; cin >> N >> M >> Q;
    vi a(Q), b(Q), c(Q), d(Q);
    rep(i, Q) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        --a[i]; --b[i];
    }

    vector<vector<vector<int>>> comb(N + 1, vvi());
    for (int i = 1; i <= 1; i++) {
        comb[1].push_back({ i });
    }
    for (int i = 1; i < N; i++) {
        for (auto& v : comb[i]) {
            // 単調増加なので、末尾の値以上であるものを全て試す
            int b = v.back();
            for (int a = b; a <= M; a++) {
                auto v2 = v;
                v2.push_back(a);
                comb[i + 1].push_back(v2);
            }
        }
    }
    
        int ans = 0;
        for (auto& v : comb[N]) {
            int res = 0;
            for (int i = 0; i < Q; i++) if (v[b[i]] - v[a[i]] == c[i]) res += d[i];
            ans = max(ans, res);
        }

        cout << ans << endl;
}

