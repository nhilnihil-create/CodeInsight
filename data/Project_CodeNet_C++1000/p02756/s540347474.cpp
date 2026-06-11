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
string s;
int q;
cin>>s>>q;
vector<int>t(q);
vector<int>f(q);
vector<char>c(q);
rep(i,q){
    cin>>t[i];
    if(t[i]==2){
        cin>>f[i]>>c[i];
    }
}
int x=0;

rep(i,q){
    
    if(t[i]==1){
    if(x)x=0;
    else x=1;
    continue;}
    if(t[i]==2){
        if(f[i]==1&&x==0){s=c[i]+s;}
        if(f[i]==1&&x==1){s+=c[i];}
        if(f[i]==2&&x==0){s+=c[i];}
        if(f[i]==2&&x==1){s=c[i]+s;}
    }
}
if(x==1)reverse(s.begin(),s.end());
cout<<s;
return 0;


}