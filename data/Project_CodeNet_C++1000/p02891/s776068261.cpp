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

    string s;
    int k;
    cin >> s >> k;

    string t = s, u = s;
    int tcount = 0, ucount = 0;

    int n = s.size();

    for(int i = 0;i < n-1;i ++){
        if(t.at(i) == t.at(i+1)){
            t.at(i+1) = '0';
            tcount ++;
        }
    }

    u.at(0) = '1';
    ucount ++;
    for(int i = 0;i < n-1;i ++){
        if(u.at(i) == u.at(i+1)){
            u.at(i+1) = '0';
            ucount ++;
        }
    }

    int ans = 0;
    if(t.at(0) != t.at(n-1)){
        ans = tcount * k;
    }else if(u.at(n-1) != '0' && u.at(n-1) != '1'){
        ans = tcount + ucount * (k-1);
    }else{
        ans = (tcount + ucount) * (k/2) + tcount * (k%2);
    }

    cout << ans << endl;
}