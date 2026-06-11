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
    int n,k,q;
    cin>>n>>k>>q;
    vector<int>A(q);
    rep(i,q)cin>>A[i];
    vector<int>B(n,k-q);
    rep(i,q)B[A[i]-1]++;
    rep(i,n){
    if(B[i]>0)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    }

return 0;
}