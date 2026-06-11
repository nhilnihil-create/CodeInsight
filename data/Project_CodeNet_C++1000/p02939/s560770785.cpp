#include <iostream>
#include <vector>

using namespace std;

#define repd(i,a,b) for (int i=(a);i<(b);++i)
#define rep(i,n) repd(i,0,n)
typedef long long ll;


int main(){
  string s;
  cin >> s;
  string prev = "";
  ll ans = 0;
  rep(i, s.size()){
    repd(j, 1, 3){
      string tmp = s.substr(i, j);
      // cout << tmp << endl;
      if(prev != tmp){
        ans++;
        prev = tmp;
        i += j-1;
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
