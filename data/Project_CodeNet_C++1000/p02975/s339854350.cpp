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
#define pNO cout << "NO" << endl
#define pYES cout << "YES" << endl
#define endl "\n"
#define pi 3.14159265358979
using namespace std;
using ll = long long;
signed main() {
    int N; cin >> N;
    map<int, int> mp;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        mp[x]++;
    }
    bool flag = false;
    if (mp.size() == 1) {
        auto iter = mp.begin();
        if (iter->first == 0) {
            flag = true;
        }
    }
    else if (mp.size() == 2) {
        if (N % 3 == 0) {
            auto iter = mp.begin();
            int num = iter->second;
            if (num == N / 3 && iter->first == 0) {
                flag = true;
            }
        }

    }
    else if (mp.size() == 3) {
        vi vec(3);
        if (N % 3 == 0) {
            auto iter = mp.begin();
            int cnt = 0;
            for (int i = 0; i < 3; i++) {
                int num = iter->second;
                vec[i] = iter->first;
                if (num  == N/3) {
                    cnt++;
                }
                iter++;
            }
            if (cnt == 3) {
                flag = true;
            }
        }
        
        int res = 0;
        res ^= vec[0];
        res ^= vec[1];
        res ^= vec[2];
        if (res != 0) {
            flag = false;
        }
    }

    if (flag) {
        pYes;
    }
    else {
        pNo;
    }
}