#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define INF 1001001001
#define INFll 100100100100100
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

int d[10][10];

int main(){
  int n;
  cin >> n;

  repo(i, n){
    int matubi=i%10;
    int sentou=i;
    int next=i/10;
    while(next!=0){
      sentou=next;
      next/=10;
    }
    d[sentou][matubi]++;
  }
  ll ans=0;
  rep(i,10){
    ans+=d[i][i]*d[i][i];
  }
  rep(i, 10){
    for(int j=i+1; j<10; j++){
      ans+=d[i][j]*d[j][i]*2;
    }
  }
  cout << ans << endl;
  return 0;
}
