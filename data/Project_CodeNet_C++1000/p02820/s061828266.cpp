#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)

int main(){
  int n,k;
  cin >> n >> k;
  ll p,r,s;
  cin >> r >> s >> p;
  string t;
  cin >> t;
  vector<int> mod(k,0);
  ll ans = 0;

  rep(i,t.size()){
    if (t[i] == 'r'){
      if (mod[i%k] == 1){
        mod[i%k] = 0;
        continue;
      }
      else{
        ans += p;
      }
      mod[i%k] = 1;
    }
    else if (t[i] == 's'){
      if (mod[i%k] == 2){
        mod[i%k] = 0;
        continue;
      }
      else{
        ans += r;
      }
      mod[i%k] = 2;
    }
    else if (t[i] == 'p'){
      if (mod[i%k] == 3){
        mod[i%k] = 0;
        continue;
      }
      else ans += s;
      mod[i%k] = 3;
    }
    //cout << i << ":" << ans << endl;
  }
  cout << ans << endl;

  return 0;
}
