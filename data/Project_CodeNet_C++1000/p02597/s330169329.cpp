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
    string c; cin >> c;

    int lwcount = 0,rrcount = 0;

    int wcount = 0, rcount = 0;

    for(int i = 0;i < n;i ++){
        if(c.at(i) == 'W') wcount ++;
        else rcount ++;
    }

    for(int i = 0;i < rcount;i ++){
        if(c.at(i) == 'W') lwcount ++;
    }
    for(int i = 0;i < wcount;i ++){
        if(c.at(n-1-i) == 'R') rrcount ++;
    }

    cout << max(lwcount,rrcount) << endl;
}