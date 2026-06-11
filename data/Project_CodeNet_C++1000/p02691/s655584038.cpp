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
#include <cmath>
#include <limits>
using namespace std;
using ll = long long;

int main(){
  int N;
  cin >> N;
  vector<int> A(N),B(N);
  for(int i=0;i<N;i++){
    cin >> A[i];
    B[i]=A[i];
    B[i]+=i+1;
  }
  sort(B.begin(),B.end());
  ll ans=0;
  for(int i=0;i<N;i++){
    if(i+1-A[i]<=1){
      continue;
    }
    ans+=upper_bound(B.begin(),B.end(),i+1-A[i])-lower_bound(B.begin(),B.end(),i+1-A[i]);
  }
  cout << ans << endl;
}