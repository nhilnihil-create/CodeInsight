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

    int k; cin >> k;
    vector<int> a(k+1);

    a.at(0) = 7 % k;

    for(int i = 1;i < k+1;i ++){
        a.at(i) = ((a.at(i-1) * 10) + 7) % k;
    }

    int ans = -1;
    for(int i = 0;i < k+1;i ++){
        if(a.at(i) == 0){
            ans = i+1;
            break;
        }
    }

    cout << ans << endl;
}