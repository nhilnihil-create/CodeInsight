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

ll pow(ll x, ll n) { //x^nの計算
  ll res = 1;
  while (n > 0) {
    if (n & 1){
      res *= x;  // n の最下位bitが 1 ならば x^(2^i) をかける
    }
    x *= x;
    n >>= 1;  // n を1bit 左にずらす
  }
  return res;
}

int main(){
  ll N;
  cin >> N;
  int k=1;
  while(26*(pow(26,k)-1)<25*N){
    k++;
  }
  vector<char> alp(k);
  N-=26*(pow(26,k-1)-1)/25+1;
  for(int i=0;i<k;i++){
    alp[k-i-1]=(char)('a'+N%26);
    N/=26;
  }
  for(int i=0;i<k;i++){
    cout << alp[i];
  }
  cout << endl;
}