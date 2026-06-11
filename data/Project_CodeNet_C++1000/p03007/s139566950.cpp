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
#define int ll
signed main() {
    int N; cin >> N;
    queue<int> sa, sb;
    vi va, vb;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        if (x > 0) {
            va.push_back(x);
        }
        else {
            vb.push_back(x);
        }
    }
    sort(ALL(va));
    sort(ALL(vb));
    reverse(ALL(vb));

    vvi ans;
    for (auto a : va) {
        sa.push(a);
    }

    for (auto b : vb) {
        sb.push(b);
    }

    while (sa.size() + sb.size() > 2) {

        if (sa.empty()) {
            int u = sb.front(); sb.pop();
            int v = sb.front(); sb.pop();
            ans.push_back({ u,v });
            sa.push(u - v);
            continue;
       }

        if (sb.empty()) {
            int u = sa.front(); sa.pop();
            int v = sa.front(); sa.pop();
            ans.push_back({ u,v });
            sb.push(u-v);
            continue;
        }

        if (sa.size() > 1) {
            int u = sa.front(); sa.pop();
            int v = sb.front(); sb.pop();

            ans.push_back({ v,u });
            sb.push(v-u);
            continue;
        }

        if (sb.size() > 1) {
            int u = sa.front(); sa.pop();
            int v = sb.front(); sb.pop();

            ans.push_back({ u,v });
            sa.push(u - v);
            continue;
        }
    }
    //size is always 2

    if (sa.empty()) {
        int u = sb.front(); sb.pop();
        int v = sb.front(); sb.pop();
        ans.push_back({ v,u });
        cout << v-u << endl;
    }else if (sb.empty()) {
        int u = sa.front(); sa.pop();
        int v = sa.front(); sa.pop();

        ans.push_back({u,v });
        cout << u - v << endl;
    }
    else {
        int u = sa.front();
        int v = sb.front();
        ans.push_back({ u,v });
        cout << u - v << endl;
    }

    for (auto v : ans) {
        cout << v[0] << " " << v[1] << endl;
    }
}