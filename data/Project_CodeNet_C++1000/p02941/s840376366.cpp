#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define N 200010
ll a[N],b[N],n,ans;
void calc(){
    for(int i=0;i<n;i++){
	int j=(i+1)%n,k=(i+2)%n;
	ll p=b[i]+b[k];
	ll cnt=(b[j]-a[j])/p;
	ans+=cnt;
	b[j]-=cnt*p;
	//cout<<p<<" "<<cnt<<" "<<(b[j]-a[j])<<":";
    }
    //for(int i=0;i<n;i++)cout<<b[i]<<" ";cout<<endl;
}
int main(){
  cin>>n;
  for(int i=0;i<n;i++)cin>>a[i];
  for(int i=0;i<n;i++)cin>>b[i];
  ans=0;
  for(int i=0;i<100;i++)calc();
  bool ok=1;
  for(int i=0;i<n;i++)ok&=(a[i]==b[i]);
  if(ok)cout<<ans<<endl;
  else cout<<-1<<endl;
  return 0;
}
