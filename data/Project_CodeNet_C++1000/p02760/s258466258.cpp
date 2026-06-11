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
    vector< vector<int> >a(3,vector<int>(3));
    rep(i,3)rep(j,3){
        cin>>a[i][j];
    }
int n;
cin>>n;
vector<int>b(n);
rep(i,n)cin>>b[i];
rep(i,n)rep(j,3)rep(k,3){
    if(b[i]==a[j][k])a[j][k]=-1;
}
rep(i,3){
    bool x=true;
    rep(j,3){
   if(a[i][j]!=-1)x=false;}
   if(x){cout<<"Yes";return 0;}
}
rep(i,3){
    bool x=true;
    rep(j,3){
   if(a[j][i]!=-1)x=false;}
   if(x){cout<<"Yes";return 0;}
}
if(a[0][0]==-1&&a[1][1]==-1&&a[2][2]==-1){cout<<"Yes";return 0;}
if(a[1][1]==-1&&a[0][2]==-1&&a[2][0]==-1){cout<<"Yes";return 0;}
cout<<"No";
return 0;
}