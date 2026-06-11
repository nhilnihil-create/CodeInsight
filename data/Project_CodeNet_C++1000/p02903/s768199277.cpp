#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;

int main() {
  int H,W,A,B;
  cin>>H>>W>>A>>B;
  for(int i = 0; i < H; i++){
    int t = 0;
    if(i<B) t = 1;
    for(int j = 0; j < W; j++){
      if(j<A)cout<<1-t;
      else cout<<t;
    }
    cout<<endl;
  }
}