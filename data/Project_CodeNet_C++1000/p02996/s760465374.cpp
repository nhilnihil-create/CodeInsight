#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;
const long long MOD=1e09+7;



#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,m,n) for(int i=m;i<n;i++)
#define ALL(v) v.begin(), v.end()




int main(){
  
  ll n;
  cin>>n;
  
  vector<ll> as(n);
  vector<ll> bs(n);
  vector<pair<ll,ll>> limit(n,pii());
  
  rep(i,n){
    ll a,b;
    cin>>a>>b;
    as.at(i)=a;
    bs.at(i)=b;
    auto tmp=make_pair(b,a);
    limit.at(i)=tmp;
  }
  
  sort(ALL(limit));
  
  ll time=0;
  string answer="Yes";
  
  rep(i,n){
    if (time+limit.at(i).second<=limit.at(i).first){
      time+=limit.at(i).second;
    }
    else {
      answer="No";
      break;
    }
  }
  
  cout<<answer<<endl;
  

  

}








