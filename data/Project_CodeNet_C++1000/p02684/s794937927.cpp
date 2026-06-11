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
    ll n,k;
    cin>>n>>k;
    vector<ll>a(n+1);
    for(int i=1;i<n+1;i++)cin>>a[i];
    vector<ll>b(n+1);
    int x=1;
    int count=0;
    while(1){
        if(b[x]==0)b[x]=1;
        if(b[a[x]]==1)break;
        x=a[x];count++;
    }
int y=a[x];
count++;

int e=0;
x=1;
while(1){
    if(x==y)break;
    x=a[x];e++;
}
if(k<=e){
    x=1;
    while(k>0){
       x=a[x]; k--;
    }
    cout<<x;
    return 0;
}
int f=count-e;
int q=(k-e)%f;
while(q>0){
y=a[y];q--;
}
cout<<y;
return 0;
}