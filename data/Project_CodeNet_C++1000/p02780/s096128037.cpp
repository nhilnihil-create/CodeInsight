#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;
const double pi=acos(-1);





int main() 
{
  ll N,K; cin>>N>>K;
  vector<double> E(N);
  rep(i,N)
  {
    double p; cin>>p;
    E.at(i)=(p+1)/2;
  }
  /*
  rep(i,N)
  {
    if(i!=0) cout<<" ";
    cout<<E.at(i);
  }
  cout<<endl;
  */
  double sum=0;
  rep(i,K)
  {
    sum+=E.at(i);
  }
  
  double ans=sum;
  for(int i=K;i<=N-1;i++)
  {
    sum+=E.at(i);
    sum-=E.at(i-K);
    ans=max(sum,ans);
    //if(i!=K) {cout<<" ";}
    //cout<<sum;
  }
  cout<<fixed<<setprecision(15)<<ans<<endl;
  return 0;
}
