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
#include <math.h>
#include <iomanip>
using namespace std;
#define int long long

signed main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0;i < n;i ++) cin >> a.at(i);

    int allxor = 0;
    for(int i = 0;i < n;i ++) allxor = allxor ^ a.at(i);

    vector<int> ans(n);
    for(int i = 0;i < n;i ++) ans.at(i) = allxor ^ a.at(i);

    for(int i = 0;i < n;i ++) cout << ans.at(i) << " ";
    cout << endl;
}