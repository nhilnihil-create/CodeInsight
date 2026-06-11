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

    int n,k; cin >> n >> k;
    vector<double> a(n);
    for(int i = 0;i < n;i ++) cin >> a.at(i);

    int ans = 100000000000000;

    sort(a.begin(),a.end(),greater<int>());

    int count;

    int l = 1,r = a.at(0) + 1;
    int mid;
    while(l != r){
        count = 0;
        mid = (l+r) / 2;
        for(int i = 0;i < n;i ++){
            int tmp = ((a.at(i)/(double)mid)-0.000000000001);
            count += tmp;
            //cout << mid << " " << ((a.at(i)/(float)mid)-0.000000000001) << endl;
        }

        if(count <= k){
            ans = min(ans,mid);
        }

        if(count <= k) r = mid;
        else l = mid + 1;
    }

    cout << ans << endl;
}