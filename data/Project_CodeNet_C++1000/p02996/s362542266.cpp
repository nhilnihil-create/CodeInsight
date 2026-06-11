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
#include <iomanip> // fixed, setprecision 
#include <math.h> // double sqrt
#define rep(i,n) for(int i=0;i<(n);++i)
#define ll long long
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<pair<int, int> > p(n);
    rep(i,n)cin>>p[i].second>>p[i].first;
    sort(p.begin(), p.end());
    int t=0;
    bool x=true;
    rep(i,n){
        t+=p[i].second;
        if(t>p[i].first){x=false;break;}
    }
if(x)cout<<"Yes";
else cout<<"No";
return 0;
}