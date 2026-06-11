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

    int h,w,k; cin >> h >> w >> k;
    vector<vector<char> > c(h,vector<char>(w));

    for(int i = 0;i < h;i ++){
        for(int j = 0;j < w;j ++){
            cin >> c.at(i).at(j);
        }
    }

    vector<vector<char> > d(h,vector<char> (w));

    vector<int> seni(h+w+1);

    int ans = 0;
    int count;

    while(seni.at(0) == 0){
        for(int i = 0;i < h;i ++){
            for(int j = 0;j < w;j ++) d.at(i).at(j) = c.at(i).at(j);
        }

        for(int i = 0;i < h;i ++){
            if(seni.at(h+w-i) == 1){
                for(int j = 0;j < w;j ++) d.at(i).at(j) = '.';
            }
        }
        for(int i = 0;i < w;i ++){
            if(seni.at(w-i) == 1){
                for(int j = 0;j < h;j ++) d.at(j).at(i) = '.';
            }
        }

        count = 0;
        for(int i = 0;i < h;i ++){
            for(int j = 0;j < w;j ++){
                if(d.at(i).at(j) == '#') count ++;
            }
        }

        if(count == k) ans ++;

        seni.at(h+w) ++;

        for(int i = h+w;i > 0;i --){
            if(seni.at(i) > 1){
                seni.at(i) = 0;
                seni.at(i-1) ++;
            }
        }
    }

    cout << ans << endl;
}