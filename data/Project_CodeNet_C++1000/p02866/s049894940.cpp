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
    vector<int> d(n);
    for(int i = 0;i < n;i ++) cin >> d.at(i);

    if(n == 1){
        if(d.at(0) == 0)cout << 1 << endl;
        else cout << 0 << endl;
        return 0;
    }
    if(d.at(0) > 0){
        cout << 0 << endl;
        return 0;
    }
    for(int i = 1;i < n;i ++){
        if(d.at(i) == 0){
            cout << 0 << endl;
            return 0;
        }
    }
    
    int m = 0;
    for(int i = 0;i < n;i ++) m = max(m,d.at(i));
    vector<int> kazoe(m+1);
    for(int i = 0;i < n;i ++){
        kazoe.at(d.at(i)) ++;
    }

    int ans = 1;
    for(int i = 1;i < m+1;i ++){
        for(int j = 0;j < kazoe.at(i);j ++){
            ans *= kazoe.at(i-1);
            ans %= 998244353;
        }
    }

    cout << ans << endl;
}