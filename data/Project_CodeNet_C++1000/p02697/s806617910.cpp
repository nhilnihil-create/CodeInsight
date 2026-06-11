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
		int n,m;
		cin>>n>>m;
		set<int,greater<int>> s,s1;
		for(int i=1;i<=n;i++)
		s.insert(i);
		while(m--){
			int x=*s.rbegin(),y=-1;
			int i=x;
			for(auto j:s){
				if(i==j||n-j+i==j-i||s1.count(abs(i-j))==true||s1.count(abs(n-j+i))==true){
					continue;
				}
				x=i;
				y=j;
				break;
			}
			cout<<x<<" "<<y<<endl;
			s1.insert(y-x);
			s1.insert(n-y+x);
		//	cout<<y-x<<" "<<n-y+x<<endl;
			s.erase(x);
			s.erase(y);
		}
	}
	return 0;
}