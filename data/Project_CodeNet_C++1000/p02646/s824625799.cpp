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
using namespace std;

long long MAX = 1e18;

int main() {
long long a, b, v, w, t;
cin >> a >> v >> b >> w >> t;
for(int i = 1; i <= t; i++){
    if(a > b){
        a = a - v;
        b = b - w;
        if(a <= b){
            cout << "YES" << endl;
            return 0;
        }
    }else{
        a = a + v;
        b = b + w;
        if(a >= b){
            cout << "YES" << endl;
            return 0;
        }
    }
}

cout << "NO" << endl;

return 0;
}
