#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) begin(x), end(x)
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
using namespace std;
typedef long long ll;
typedef pair <int,int> P;

int main(){
  ll a,b,c,d;
  cin>>a>>b>>c>>d;
  
  cout<<max(max(a*c,a*d),max(b*c,b*d))<<endl;
  return 0;
}
