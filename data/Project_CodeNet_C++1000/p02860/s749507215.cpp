#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<long long,long long>
#define ii pair<int,int>
#define mod 1000000007
#define endl '\n'
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);

ll power(ll a,ll b){
	ll ans=1;
	while(b>0){
		if(b%2!=0){
			ans=(ans*a)%mod;
		}
		a=((a%mod)*(a%mod))%mod;
		b>>=1;
	}
	return ans;
}

void sieve(int n){
	bool prime[n+1];
	memset(prime,true,sizeof(prime));
	for(int p=2;p*p<=n;p++){
		if(prime[p]){
			for(int i=p*p;i<=n;i+=p)
				prime[i]=false;
		}
	}
	for(int p=2;p<=n;p++){
		if(prime[p])
			cout<<p<<" ";
	}
}

int main() {
	IOS;
	int t=1;
	//cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		if(s.size()%2!=0){
			cout<<"No";
			return 0;
		}
		int i=0,j=s.size()/2;;
		while(j<s.size()){
			if(s[i]!=s[j]){
				cout<<"No";
				return 0;
			}
			i++;
			j++;
		}
		cout<<"Yes";
	}
	return 0;
}