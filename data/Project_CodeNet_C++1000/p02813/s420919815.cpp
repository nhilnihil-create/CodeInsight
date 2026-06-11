#include<iostream>
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
#include <iomanip>//setprecision
#include<math.h>
#include <functional>
#include<climits>
using namespace std;
#define ll  long long 
#define rep(i, n)        for(ll i=0; i<(ll)(n); ++i)
#define mod 1000000007
  //vector<ll>to[1000005];
  // ll dp[2000000];
 int gcd(int a, int b)
{
  if (a%b == 0)
{
return(b);
}
else
{
return(gcd(b,a%b));
}
}
int main(){
  ll a,c=0,d=-1,e=-1;cin>>a;
  char b;
  string x,y,z;
  rep(i,a){
    cin>>b;
    x.push_back(b);
    z.push_back(i+'1');
  }
  //cout<<z[0];
    rep(i,a){
    cin>>b;
    y.push_back(b);
  }
  do{
    if(x==z)d=c;
    if(z==y)e=c;
    c++;
    if(d!=-1&&e!=-1)break;
  }while(next_permutation(z.begin(),z.end()));
  cout<<abs(d-e);
}

