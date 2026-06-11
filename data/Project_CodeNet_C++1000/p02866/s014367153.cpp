#include <bits/stdc++.h>
#define r(i,n) for(int i = 0; i<n; i++)
typedef long long ll;
using namespace std;
const ll mod=998244353;

int main(){
  bool flag=true;
  ll n,ans=1;
  cin >> n;
  map<int,int> mp;
  mp[0]=0;
  r(i,n){
    int a;
    cin >> a;
    mp[a]++;
    if(i==0&&a!=0)flag=false;
    if(i!=0&&a==0)flag=false;
  }
  if(!flag)cout<<0<<endl;
  else{
    int m=1,p=1;
    for(auto it=mp.begin();it!=mp.end();it++){
      if(it==mp.begin())continue;
      if((*it).first!=m)ans=0;
      else {
        r(i,(*it).second){
          ans*=p;
          ans%=mod;
        }
        m++;
        p=(*it).second;
      }
    }
    cout<<ans<<endl;
  }
}
