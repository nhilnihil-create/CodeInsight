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
#include<cmath>
#include<limits>
#define ll long long
#define ALL(x) (x).begin(),(x).end()
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define int_INF 2147483647
#define pint_INF 2000000000
#define ll_INF 	9223372036854775807
#define MOD 1000000007
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
using namespace std;

int main() {
    ll N, K; cin >> N >> K;
    vi A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    ll temp1 = 0, temp2 = 0;

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (A[i] > A[j]) {
                temp1++;
            }
            else if (A[i] < A[j]) {
                temp2++;
            }
        }
    }

    ll ans1, ans2;
    ans1 = K * (K + 1) / 2;

    ans1 %= MOD;
    ans1 *= temp1;

    ans2 = K * (K - 1) / 2;
    ans2 %= MOD;
    ans2 *= temp2;

    ll ans = ans1 + ans2;
    ans %= MOD;

    cout << ans << endl;

}
