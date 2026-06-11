#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(i = 0; i < n; i++)
//2D::rep(i,j)rep(j,j)cin>>bin[i][j];
//vector<int> a(n)
#define A1 cout<<"No"<<endl
#define A2 cout<<"Yes"<<endl
#define A3 cout<<ans<<endl
#define AA(i) cout<<i<<endl
const int U=2e5+5;
const ll MOD=998244353;
const int INF = 1001001001;
#define size 200010

int main(){
  ll N; cin >> N; 
  ll A,B; cin>> A >> B;
  if((B-A)%2 == 0) AA((B-A)/2);
  else AA(min((B-1+A-1+1)/2,(N-A+N-B+1)/2));
  return 0;
}