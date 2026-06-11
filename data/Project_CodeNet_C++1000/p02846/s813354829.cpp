#include <bits/stdc++.h> 

using namespace std;
using ll=long long int;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()
#define endl "\n"

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll T1,T2,A1,A2,B1,B2;
  cin>>T1>>T2>>A1>>A2>>B1>>B2;
  B1-=A1;
  B2-=A2;
  if((B1>0&&B2>0)||(B1<0&&B2<0))cout<<0<<endl;
  else if(abs(B1*T1)>abs(B2*T2))cout<<0<<endl;
  else if(abs(B1*T1)==abs(B2*T2))cout<<"infinity"<<endl;
  else{
    ll D=abs(B2*T2)-abs(B1*T1);
    ll ans=2*((abs(B1*T1))/D)+1;
    if(abs(B1*T1)%D==0)ans--;
    cout<<ans<<endl;
  }

  return 0;
}
