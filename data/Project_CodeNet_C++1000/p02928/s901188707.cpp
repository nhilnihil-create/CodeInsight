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

    int n,k; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0;i < n;i ++) cin >> a.at(i);

    vector<int> cnta(n),cntb(2001),cntc(n);

    for(int i = 0;i < n;i ++){
        for(int j = i;j < n;j ++){
            if(a.at(i) > a.at(j)) cnta.at(i) ++;
        }
    }

    for(int i = 0;i < n;i ++){
        cntb.at(a.at(i)) ++;
    }

    for(int i = 0;i < n;i ++){
        for(int j = 0;j < a.at(i);j ++){
            cntc.at(i) += cntb.at(j);
        }
    }

    int ans = 0;

    for(int i = 0;i < n;i ++){
        ans += cnta.at(i) * k;
        ans %= 1000000007;
        int x = k * (k-1) / 2;
        x %= 1000000007;
        ans += cntc.at(i) * x;
        ans %= 1000000007; 
    }

    cout << ans << endl;

}