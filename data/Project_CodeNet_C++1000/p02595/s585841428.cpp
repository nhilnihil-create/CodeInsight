#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const ll INF=1e18;


int main() {
  ll n,d,x,y,ans=0;
  long double w;
  cin >> n >> d;
  rep(i,n){
    cin >> x >> y;
    w = sqrt(pow(x,2)+pow(y,2));
    if(w <= d) ans++;
  }
  cout << ans << endl;
}