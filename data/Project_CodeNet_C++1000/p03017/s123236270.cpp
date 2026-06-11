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

    int n,a,b,c,d;
    string s;
    cin >> n >> a >> b >> c >> d >> s;

    a --;
    b --;
    c --;
    d --;

    bool or2 = true, or3 = true;

    for(int i = a;i < c;i ++){
        if(s.at(i) == '#' && s.at(i+1) == '#') or2 = false;
    }
    for(int i = b;i < d;i ++){
        if(s.at(i) == '#' && s.at(i+1) == '#') or2 = false;
    }

    if(c > d){
        or3 = false;
        for(int i = b-1;i < d;i ++){
            if(s.at(i)=='.'&&s.at(i+1)=='.'&&s.at(i+2)=='.') or3 = true;
        }
    }

    if(or2 && or3) cout << "Yes" << endl;
    else cout << "No" << endl;

}