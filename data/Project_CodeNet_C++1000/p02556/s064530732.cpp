#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) begin(x), end(x)
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
using namespace std;
typedef long long ll;
typedef pair <int,int> P;

int main(){
  int n;
  cin>>n;
  int pp[200005],pm[200005];
  rep(i,n){
    int x,y;
    cin>>x>>y;
    pp[i]=x+y;
    pm[i]=x-y;
  }
  sort(pp,pp+n);
  sort(pm,pm+n);
  cout<<max(pp[n-1]-pp[0],pm[n-1]-pm[0])<<endl;
  return 0;
}
