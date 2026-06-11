#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  
  int C[10][10];
  rep(i,10){
    rep(j,10) C[i][j]=0;
  }
  for(int i=1;i<=n;i++){
    int a=i;
    while(a>=10) a/=10;
    C[a][i%10]++;
  }
  
  int sum=0;
  rep(i,10){
    rep(j,10){
      sum+=C[i][j]*C[j][i];
    }
  }
  
  cout<<sum<<endl;
  
  return 0;
}