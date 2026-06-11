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

    int n;
    string s;
    cin >> n >> s;

    vector<vector<int> > a(10,vector<int>(30010));

    for(int i = 0;i < n;i ++){
        int x = s.at(i) - '0';
        a.at(x).at(i+1) ++;
    }

    for(int i = 0;i < 10;i ++){
        for(int j = 1;j < 30001;j ++){
            a.at(i).at(j) = a.at(i).at(j-1) + a.at(i).at(j);
        }
    }

    int ans = 0;

    for(int i = 0;i < 10;i ++){
        for(int j = 0;j < 10;j ++){
            for(int k = 0;k < 10;k ++){
                int hantei = 0;
                int me = 1;
                
                while(a.at(i).at(me-1) == a.at(i).at(me) && me < 30001){
                    me ++;
                }
                me ++;
                while(me < 30001 && a.at(j).at(me-1) == a.at(j).at(me)){
                    me ++;
                }
                
                if(me < 30001 && a.at(k).at(30000) - a.at(k).at(me) > 0) hantei = 1;
                

                if(hantei) ans ++;                
            }
        }
    }

    cout << ans << endl;
}