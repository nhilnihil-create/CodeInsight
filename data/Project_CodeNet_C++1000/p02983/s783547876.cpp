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
#include <cmath>
#include <math.h> // sqrt()

using namespace std;

int main(){
    int l, m, small;
    cin >> l >> m;
    vector<int> num;
    if (m / 2019 != l / 2019 || m % 2019 == 0){
        cout << 0 << endl;
        return 0;
    }
    small = 2021;
    int remain = l % 2019;
    for (int i = remain; i <= m - l + remain; i++){
        for (int x = remain; x <= m - l + remain; x++){
            if (i != x){
                small = min(small , i * x % 2019);
            }
        }
    }
    cout << small << endl;



}