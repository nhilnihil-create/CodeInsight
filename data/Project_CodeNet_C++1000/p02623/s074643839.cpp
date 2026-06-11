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

    int n,m,k; cin >> n >> m >> k;
    vector<int> a(n),b(m);
    for(int i = 0;i < n;i ++) cin >> a.at(i);
    for(int i = 0;i < m;i ++) cin >> b.at(i);

    vector<int> asum(n+1),bsum(m+1);
    for(int i = 1;i < n+1;i ++) asum.at(i) = asum.at(i-1) + a.at(i-1);
    for(int i = 1;i < m+1;i ++) bsum.at(i) = bsum.at(i-1) + b.at(i-1);

    int ans = 0;

    for(int i = n;i >= 0;i --){
        if(asum.at(i) > k) continue;

        auto iter = lower_bound(bsum.begin(),bsum.end(),k-asum.at(i)+1);
        int temp = iter - bsum.begin();

        ans = max(ans, i+temp-1);
    }

    cout << ans << endl;
    
}