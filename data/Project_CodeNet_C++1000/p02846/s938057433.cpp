#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi=vector<int>;
using vvi=vector<vi>;
using vl=vector<ll>;
using vvl=vector<vl>;
using vb=vector<bool>;
using vvb=vector<vb>;
using pii = pair<int,int>;
using pli = pair<ll,int>;
using pll = pair<ll,ll>;
using vpii = vector<pii>;
using vpli = vector<pli>;
using vpll = vector<pll>;

#define rep(i, n) for(int i=0;i<(int)n;i++)
#define rep2(i, s, n) for(int i=(s);i<(int)n;i++)
int INF=1e9+7;

int main() {
  int T1,T2;
  ll A1,A2,B1,B2;
  cin >> T1>>T2>>A1>>A2>>B1>>B2;
  ll X1=(A1-B1)*T1,X2=(A2-B2)*T2;
  
  if(X1+X2==0) cout << "infinity" << endl;
  else if(X1>0&&X1+X2>0||X1<0&&X1+X2<0) cout << 0 << endl;
  else {
    if(X1<0) {
      X1*=-1;
      X2*=-1;
    }
    ll ans;
    if(X1%-(X1+X2)) ans=X1/-(X1+X2)*2+1;
    else ans=X1/-(X1+X2)*2;
    cout << ans << endl;
  }
}