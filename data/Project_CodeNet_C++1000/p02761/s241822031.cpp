#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N, M;
  cin >> N >> M;
  map<int, int> s;
  int x, y;
  
  rep(i, M){
    cin >> x >> y;
    if(s.count(x)){
      if(s.at(x) != y){
       cout << -1 << endl;
       return 0;
      }
    }else s[x] = y;
  }
  if(N != 1 && s.count(1) && s.at(1)==0){
   cout << -1;
  }else{
    for(int i=1; i<=N; i++){
     if(s.count(i)) cout << s.at(i);
     else if(i==1 && N!=1) cout << 1;
     else cout << 0;
    }
  }
  cout << endl;
  return 0;
}


