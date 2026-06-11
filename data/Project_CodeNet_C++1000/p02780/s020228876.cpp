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
    int n,k;
    cin>>n>>k;
    vector<int>p(n+2);
    rep(i,n)cin>>p[i];
    int ans=0;
    int __max=0;
    double x=0;
    vector<int> s(n+2, 0); // s[0] = 0 になる
for (int i = 0; i < n+1; ++i) s[i+1] = s[i] + p[i];
    rep(i,n-k+1){
        __max=max(s[i+k]-s[i],__max);
        if(max(s[i+k]-s[i],__max)==s[i+k]-s[i])ans=i;
    }
    int aaa=ans;
while(ans<aaa+k){
    x+=(double)(1+p[ans])/2.0;
    ans++;
}
cout<<fixed<<setprecision(8)<<x;
return 0;
}