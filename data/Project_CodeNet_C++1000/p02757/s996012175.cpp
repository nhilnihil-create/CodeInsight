#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define F first
#define S second

using namespace std;
typedef pair<int,int> P;

const int MOD=1000000007;
int INF=100100100100100;
map<int,int> ma;
int beki[200010];
int a[200010];
signed main(){
  int n,p;cin>>n>>p;
  string s;cin>>s;
  int ans=0;
  if(p==2 || p==5){
    rep(i,n){
      int t=s[i]-'0';
      if(t%p==0)ans+=i+1;
    }
    cout<<ans<<endl;
    return 0;
  }
  
  //p!=2,5の場合
  ma[0]++;
  rep(i,n){
    if(i==0)beki[i]=1;
    else beki[i]=(10*beki[i-1])%p;
    int t=s[n-1-i]-'0';
    if(i==0)a[0]=t%p;
    else {
      a[i]=(a[i-1]+beki[i]*t)%p;
    }
    //cout<<a[i]<<endl;
    ma[a[i]]++;
  }
  for(auto ite=ma.begin();ite!=ma.end();ite++){
    int po=ite->S;
    ans+=po*(po-1)/2;
  }
  cout<<ans<<endl;
  
  return 0;
}
