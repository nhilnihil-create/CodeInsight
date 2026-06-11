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

    int n,k,s; cin >> n >> k >> s;
    vector<int> ans(n);

    if(s < 1000000000){
        for(int i = 0;i < k;i ++) ans.at(i) = s;
        for(int i = k;i < n;i ++) ans.at(i) = 1000000000;
        for(int i = 0;i < n;i ++) cout << ans.at(i) << " ";
        cout << endl;
    }
    else{
        for(int i = 0;i < k;i ++) ans.at(i) = s;
        for(int i = k;i < n;i ++) ans.at(i) = 99999999;
        for(int i = 0;i < n;i ++) cout << ans.at(i) << " ";
        cout << endl;
    }
}