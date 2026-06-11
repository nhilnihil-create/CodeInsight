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
 
  int N;
  int ans=1;
  cin >> N;
  long H[N];
  for(int i=0; i<N; i++) cin >> H[i];
 
  for(int i=0; i<N-1; i++){
    if(H[i+1]>H[i]) H[i+1]--;
  }
 
  for(int i=1; i<N; i++){
    if(H[i]<H[i-1]) ans = 0;
  }
 
if(ans)cout<<"Yes";
  else cout<<"No";
  return 0;
}