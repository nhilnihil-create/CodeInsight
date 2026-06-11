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
    vector<int> yakusu(10000001,2);
    yakusu.at(1) = 1;
    for(int i = 2;i <= 5000000;i ++){
        for(int j = 2;;j ++){
            if(i * j >= 10000001) break;
            yakusu.at(i * j) ++;
        }
    }    

    int ans = 0;

    for(int i = 0;i < n+1;i ++) ans += i * yakusu.at(i);

    cout << ans << endl;
}