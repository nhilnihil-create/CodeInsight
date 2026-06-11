#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using i64 = int64_t;
using ll = long long;
int main() {
  ll n;
  cin >> n;
  vector<string> s(n);
  rep(i,n){
    cin >> s.at(i);
  }
  sort(s.begin(),s.end());
  ll kind=1;
  rep(i,n-1){
    if(s.at(i) != s.at(i+1)){
      kind ++;
    }
  }
  cout << kind <<endl;
  return 0;
}