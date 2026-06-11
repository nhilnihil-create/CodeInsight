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

    int n,m; cin >> n >> m;
    vector<int> a(m);
    for(int i = 0;i < m;i ++) cin >> a.at(i);

    vector<int> b(100001);
    for(int i = 0;i < m;i ++) b.at(a.at(i)) = 1;

    vector<int> cnt(n+1);
    cnt.at(0) = 1;
    if(b.at(1) == 0) cnt.at(1) = 1;

    for(int i = 2;i < n+1;i ++){
        if(b.at(i) == 0) cnt.at(i) = cnt.at(i-2) + cnt.at(i-1);
        cnt.at(i) %= 1000000007;
    }

    cout << cnt.at(n) << endl;

}