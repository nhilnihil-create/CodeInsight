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
    vector<int> a(n);
    for(int i = 0;i < n;i ++) cin >> a.at(i);

    map<int,int> mp;
    for(int i = 0;i < n;i ++) mp[a.at(i)] ++;

    for(int i = 0;i < m;i ++){
        int b = mp.rbegin() -> first;
        mp[b] --;
        mp[b/2] ++;
        if(mp[b] == 0) mp.erase(b);
    }

    int ans = 0;
    for(auto i = mp.begin();i != mp.end();i ++){
        ans += i -> first * i -> second;
    }

    cout << ans << endl;

}