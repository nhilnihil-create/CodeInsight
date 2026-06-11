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
  vector< vector<int> > C(9,vector<int>(9,0));
  for(int i=1;i<=N;i++){
    if(i%10==0){
      continue;
    }
    int b=i%10;
    int t;
    int m=i;
    while(m>0){
      t=m;
      m/=10;
    }
    C[t-1][b-1]++;
  }
  ll ans=0;
  for(int i=1;i<=9;i++){
    for(int j=1;j<=9;j++){
      ans+=C[i-1][j-1]*C[j-1][i-1];
    }
  }
  cout << ans << endl;
}
