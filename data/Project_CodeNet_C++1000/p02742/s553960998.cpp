#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define rep(i,n) for(int i=0;i<n;i++)

int main() {
	ll H,W;
  	cin>>H>>W;
  	ll ans=0;
  	if(H%2==0||W%2==0) ans=H*W/2;
  	else ans=H*W/2+1;
  	
  	if(H==1||W==1) ans=1;
  	cout<<ans<<endl;
  
}	