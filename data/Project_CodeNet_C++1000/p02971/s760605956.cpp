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
using namespace std;

int main(){
int n;
cin>>n;
 vector<int>A(n);
 rep(i,n)cin>>A[i];
 vector<int>B(n);
 rep(i,n)B[i]=A[i];
sort(B.begin(),B.end());
if(B[n-2]==B[n-1]){rep(i,n)cout<<B[n-1]<<endl;return 0;}
int x=B[n-1];
int y=B[n-2];
rep(i,n){
    if(A[i]==x)cout<<y<<endl;
    else cout<<x<<endl;
    }
return 0;



}