#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,x,y) for(ll i=x;i<=y;i++)
#define imin INT_MIN
#define imax INT_MAX
int mod =1e9+7;

 
int main(){
	cin.tie(NULL);
    ios_base::sync_with_stdio();
    ll n,d; cin>>n>>d;
    ll cnt=0;
    for(int i=0; i<n; i++){
     	ll x,y; cin>>x>>y;
      	if(sqrt(x*x + y*y) <= d){
          cnt++;
        }
    }
  cout<<cnt<<"\n";
	return 0;
}