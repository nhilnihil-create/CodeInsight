#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>; // グラフ型
typedef long long ll;
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)

int main() {
  ll X;
  cin>>X;
  
  for(ll A=-3000;A<=3000;A++){
      for(ll B=-3000;B<=3000;B++){
          if(A*A*A*A*A-B*B*B*B*B==X){
              cout<<A<<" "<<B<<endl;
              return 0;
          }
      }
  }
}
