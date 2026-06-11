#include<bits/stdc++.h>
#define ll long long int
#define M 1000000007
using namespace std;
ll n,t,x,y,m,q;

int main(){
      ios_base::sync_with_stdio(false); cin.tie(NULL);
      cin>>n;
      if(n%2)cout<<0;
      else{
      	ll x=5,ans=0;
      	while(x*2<=n){
      		ans+=(n/(x*2));
      		x*=5;
      	}
      	cout<<ans;
      }
}