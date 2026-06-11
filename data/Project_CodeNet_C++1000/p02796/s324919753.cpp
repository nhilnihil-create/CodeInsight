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
    vector<int> x(n),l(n);
    for(int i = 0;i < n;i ++) cin >> x.at(i) >> l.at(i);

    vector<pair<int,int> > xl(n);
    for(int i = 0;i < n;i ++){
        xl.at(i).first = x.at(i);
        xl.at(i).second = l.at(i);
    }
    sort(xl.begin(),xl.end());

    for(int i = 0;i < n;i ++){
        x.at(i) = xl.at(i).first;
        l.at(i) = xl.at(i).second;
    }

    if(n == 1){
        cout << 1 << endl;
        return 0;
    }

    vector<int> hantei(n,1);
    int a = 0,b = 1;
    while(a < n && b < n){
        int tuka1,tuka2;
        tuka1 = a;
        tuka2 = b;
        a = min(tuka1,tuka2);
        b = max(tuka1,tuka2);

        if(x.at(a) + l.at(a) > x.at(b) - l.at(b)){
            if(x.at(a) + l.at(a) < x.at(b) + l.at(b)){
                hantei.at(b) = 0;
                b ++;
                continue;
            }else{
                hantei.at(a) = 0;
                a = b+1;
                continue;
            }
        }

        a = b + 1;

    }

    int ans = 0;
    for(int i = 0;i < n;i ++) ans += hantei.at(i);

    cout << ans << endl;
}