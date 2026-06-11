#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+9;
ll n,d[N],c[N];
ll solve(ll sum){
  if(sum<=9)return 0;
  return sum/10+solve(sum%10+sum/10);
}
int main(){
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  cin>>n;
  ll sum=0,sumn=0;
 // bool flag=1;
  for(int i=1;i<=n;i++){
    cin>>d[i]>>c[i];
    sum+=1ll*d[i]*c[i],sumn+=c[i];
  }
  ll ans=sumn-1+solve(sum);
  cout<<ans<<endl;
  return 0;
}