#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) { a = b; return 1; }
  return 0; }
template<class T> inline bool chmin(T& a, T b) {
  if (a > b) { a = b; return 1; }
  return 0; }
ll MOD = 1000000007;

int main(){
  int n; cin >> n;
  vector<P> ba;
  rep(i,n){
    int a,b;
    cin >> a >> b;
    ba.push_back(make_pair(b,a));
  }
  sort(ba.begin(),ba.end());
  int count = 0;
  for(int i = 0; i < n; i++){
    count += ba.at(i).second;
    if(count > ba.at(i).first){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
