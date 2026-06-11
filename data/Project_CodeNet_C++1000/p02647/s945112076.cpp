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
int N, K;
vector<int> accumulative_form_alize(vector<int> v) {
    vi res(N+2);
    for (int i = 1; i < N+1; i++) {
            int l = max(0, i - v[i]);
            int r = min(N + 1, i + v[i]+1);

            res[l]++;
            res[r]--;
    }
    return res;
}

vector<int> Sum_form_alize(vi v) {//input is acc form
    vi res(N + 2);
    res[0] = v[0];

    for (int i = 1; i < N+1; i++) {
        res[i] = res[i - 1] + v[i];
    }
    res[0] = 0;
    res[N + 1] = 0;
    return res;
}

vi next(vi v) {// input is sum form
    vi v1 = accumulative_form_alize(v);
    return Sum_form_alize(v1);
}
int main() {
    cin >> N >> K;
    vector<int> vec(N+2);
    for (int i = 1; i < N + 1; i++) {
        cin >> vec[i];
   }
    int M = 50;
    vector<vi> ans(M);
    ans[0] = vec;
    for (int i = 1; i < M; i++) {
        ans[i] = next(ans[i - 1]);
    }
    K = min(K, M-1);

    for (int i = 1; i < N + 1; i++) {
        cout << ans[K][i] << " ";
    }
}