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

    double a,b,x; cin >> a >> b >> x;
    double y;
    if(x <= a*a*b/2) y = 2 * x / (b * a);
    else{
        double z = a * a * b - x;
        y = 2 * z / (a * a);
    }

    if(x <= a*a*b/2)cout << fixed << setprecision(10) << atan(b / y) * 180.0 / 3.14159265358979<< endl;
    else cout << fixed << setprecision(10) << 90 - atan(a / y) * 180.0 / 3.14159265358979 << endl;
}