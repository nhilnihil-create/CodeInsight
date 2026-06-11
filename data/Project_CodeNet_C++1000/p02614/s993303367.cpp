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
  int H,W,K;
  cin >> H >> W >> K;
  vector<string> C(H);
  for(int i=0;i<H;i++){
    cin >> C[i];
  }
  int ans=0;
  for(int i=0;i<(1<<H);i++){
    for(int j=0;j<(1<<W);j++){
      int count=0;
      for(int k=0;k<H;k++){
        for(int l=0;l<W;l++){
          if(i&(1<<k) || j&(1<<l)){
            continue;
          }
          if(C[k][l]=='#'){
            count++;
          }
        }
      }
      if(count==K){
        ans++;
      }
    }
  }
  cout << ans << endl;
}