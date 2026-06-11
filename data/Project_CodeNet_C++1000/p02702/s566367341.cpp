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
  string S;
  cin >> S;
  int N=S.size();
  vector<int> dp(2020,0);
  dp[0]=1;
  int now=0;
  int k=1;
  for(int i=N-1;i>=0;i--){
    now=(now+k*(S[i]-'0'))%2019;
    dp[now]++;
    k=k*10%2019;
  }
  ll ans=0;
  for(int i=0;i<=2018;i++){
    ans+=dp[i]*(dp[i]-1)/2;
  }
  cout << ans << endl;
}