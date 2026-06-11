#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
 


int main(){
  int n;
  cin >> n;
  vector<ll> a(n);
  ll sum=0;
  rep(i,n){
    cin >> a.at(i);
    sum+=a.at(i);
  }
  int k;
  ll suma=0;
  rep(i,n){
    suma+=a.at(i);
    if(2*suma>=sum){
     k=i;
      break;
    }
  }
  ll sumb=suma-a.at(k);
  ll difa=2*suma-sum;
  ll difb=sum-2*sumb;
  ll ans=min(difa,difb);
  cout << ans << endl;
  
}