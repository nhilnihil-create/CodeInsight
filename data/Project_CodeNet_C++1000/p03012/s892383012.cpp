#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
const int INF=1e9+5;
typedef long long ll;

int main() {
  ll N;
  cin>>N;
  ll w[N];
  ll a=0,b=0;
  cin>>w[0];
  a+=w[0];
  for(int i=1;i<N;i++){
    cin>>w[i];
    b+=w[i];
  }
  ll ans=abs(a-b);
  for(int i=1;i<N-1;i++){
    a+=w[i];
    b-=w[i];
    ans=min(ans,abs(a-b));
  }
  cout<<ans<<endl;
            
}