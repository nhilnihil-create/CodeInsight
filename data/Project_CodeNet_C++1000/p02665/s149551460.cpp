#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()
#define endl "\n"
#define int ll

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin>>N;
  N++;
  vector<int>A(N);
  for(int i=0;i<N;i++)cin>>A[i];

  vector<int>low(N),high(N);
  for(int i=N-1;i>=0;i--){
    if(i==N-1){
      low[i]=A[i];
      high[i]=A[i];
    }
    else{
      low[i]=low[i+1]/2+low[i+1]%2+A[i];
      high[i]=high[i+1]+A[i];
    }
  }

  ll ans=0;
  for(int i=0;i<N;i++){
    if(i!=0)high[i]=min(2*(high[i-1]-A[i-1]),high[i]);
    int POW;
    if(i>=32)POW=INF;
    else POW=pow(2,i);
    high[i]=min(high[i],POW);
    ans+=high[i];
  }

  for(int i=0;i<N;i++){
    if(high[i]<low[i]){
      cout<<-1<<endl;
      return 0;
    }
  }

  cout<<ans<<endl;

  return 0;
}
