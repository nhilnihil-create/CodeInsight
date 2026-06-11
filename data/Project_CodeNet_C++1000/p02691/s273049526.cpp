#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define debug(x) cerr<<#x<<": "<<x<<endl;
#define MOD 1000000007ULL;
#define rep(i,n) for(int i=0;i<n;i++)


int main() {
	ll N;
  	cin>>N;
  	ll a[N];
  
  	rep(i,N) cin>>a[i];
  	
  	map<int,int> mp;
  	ll ans=0;
  
  	rep(i,N){
     	ll wa=a[i]+i;
      	ll sa=i-a[i];
      	mp[wa]++;
      	ans+=mp[sa];
    }
  	
  
  	cout<<ans<<endl;
}