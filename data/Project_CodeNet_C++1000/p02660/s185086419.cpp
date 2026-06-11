#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;

bool IsPrime(ll num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; 
    for (ll i = 3; i*i <= num; i += 2)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main(){
  ll N;
  cin >> N;
  ll ans = 0;
  ll M = N;
  ll j=0;
  for(ll i=2;i*i<=N+10;i++){
    if(M%i==0 && IsPrime(i)){
      ll k=i;
      while (M%k==0){
        //cout << k << endl;
	M/=k;
	k=k*i;
	ans++;
      }
    }
    j=i;
  }
  if(M>j)ans++;
  if(ans==0 && N>1) ans=1;
  cout << ans << endl;
}

/*
int main() {
  ll N;
  cin>>N;
  ll p=sqrt(N);
  vector<ll>a(p+10);
  for(ll i=0;i<p+10;i++) a[i]=0;
  ll n=N;
  ll ans=0;
  for(ll i=2;i<=p+10;i++){
    while(1){
      if(n%i==0)n/=i;
      else break;
      a[i]++;
    }
    if(n<i)break;
  }
  for(ll i=2;i<p+10;i++){
    if(a[i]!=0){
      for(ll u=1;;u++){
	if(a[i]>=u){
	  ans++;
	  a[i]-=u;
	}
	else break;
      }
    }
  }
  if(n!=1)ans++;
  if(N==1)cout<<0<<endl;
  else cout<<ans<<endl;
}
*/
