#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define chmin(a,b) if((a)>(b)) (a)=(b);
#define chmax(a,b) if((a)<(b)) (a)=(b);
#define vi vector<int>
#define pii pair<int,int>
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define pb push_back
#define pf push_front
int gcd(int a,int b){/*a>=0,b>=0,￢(a=b=0)*/
  while(min(a,b)>0){if(a<b)swap(a,b);a%=b;}return max(a,b);
}
int dx[]={1,0,-1,0,1,-1,-1,1};
int dy[]={0,1,0,-1,1,1,-1,-1};
const int MOD = 1e9+7;
const int INF = 1e18+10;

/*--------------------------------------------------------------------*/


signed main(){
  int n;
  cin>>n;
  vi x(n),y(n);
  rep(i,n) cin>>x[i]>>y[i];
  
  map<pii,int> cnt;
  rep(i,n)rep(j,n){
    if(i==j) continue;
    pii k=make_pair(x[i]-x[j],y[i]-y[j]);
    if(k.first<0){
      // k.first*=-1;
      // k.second*=-1;
    }
    cnt[k]++;
  }
  int mx=0;
  for(auto pi:cnt){
    if(pi.second>mx){
      mx=pi.second;
    }
  }
  cout<<n-mx<<endl;


  return 0;
}
