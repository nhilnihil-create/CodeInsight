#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)
// vector<vector<int>> A(3, vector<int>(4));
int main() {
  int N;
  cin>>N;
  int ans=0;
  for(int i=1; i<N; i++){
      if(i!=N-i){
          ans++;
      }
  }
  cout<<ans/2<<endl;
}

