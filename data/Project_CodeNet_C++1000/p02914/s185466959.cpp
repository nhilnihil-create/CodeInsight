#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  vector<ll> a;
  ll n,allxor=0;
  cin>>n;
  for(int i=0;i<n;i++){
    ll num;
    cin>>num;
    a.push_back(num);
    allxor^=num;
  }
  for(int i=0;i<n;i++) a[i]&=(~allxor);
  ll rnk=0;
  for(int i=59;i>=0;i--){
    int id=rnk;
    for(;id<n;id++){
      if(((a[id]>>i)&1)==1) break;
    }
    if(id==n) continue;
    if(id>rnk) a[rnk]^=a[id];
    for(int j=rnk+1;j<n;j++) a[j]=min(a[j],a[j]^a[rnk]);
    rnk++;
  }
  ll ans=0;
  for(int i=0;i<n;i++) ans=max(ans,ans^a[i]);
  cout<<ans*2+allxor<<endl;
}
