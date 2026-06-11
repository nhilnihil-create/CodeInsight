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

    int n; cin >> n;
    vector<int> a(n),b(n);
    for(int i = 0;i < n;i ++) cin >> a.at(i) >> b.at(i);

    vector<pair<int,int> > ba(n);
    for(int i = 0;i < n;i ++){
        ba.at(i).first = b.at(i);
        ba.at(i).second = a.at(i);
    }

    sort(ba.begin(),ba.end());

    int keika = 0;
    for(int i = 0;i < n;i ++){
        keika += ba.at(i).second;
        if(keika > ba.at(i).first){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}