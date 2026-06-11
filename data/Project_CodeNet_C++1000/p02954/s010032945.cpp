#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF (1<<30)-1
using ll = long long;
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  string s; cin >> s;
  int odd = 0, even = 0;
  vi ans(s.size());
  int point = 0;
  rep(i,s.size()){
    odd += i%2;
    even += 1-i%2;
    if(s.substr(i,2) == "RL") point = i;
    if(s.substr(i,2) == "LR"){
      if(point % 2 == 0){
        ans[point] = even;
        ans[point+1] = odd;
      }else{
        ans[point] = odd;
        ans[point+1] = even;
      }
      odd = even = 0;
    }
  }
  if(point % 2 == 0){
    ans[point] = even;
    ans[point+1] = odd;
  }else{
    ans[point] = odd;
    ans[point+1] = even;
  }
  rep(i,s.size()) cout << ans[i] << " ";
  cout << "\n";
  return 0;
}
