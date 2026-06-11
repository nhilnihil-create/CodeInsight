#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int,int>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
const ll INF = 1LL<<60;

int main(){
  int n; cin >> n;
  for(int i = 1; i <= 50000; i++){
    int now = i * 1.08;
    if(now == n){
      cout << i << endl;
      return 0;
    }
  }
  cout << ":(" << endl;
  return 0;
}
