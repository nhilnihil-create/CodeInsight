#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

int main(){
	
	int k,q;
	cin>>k>>q;
	vector<int> d(k);
	for(int i=0;i<k;i++)cin>>d[i];
	
	for(int i=0;i<q;i++){
		long long n,x,m;
		cin>>n>>x>>m;
		
		x%=m;
		long long S = 0;
		for(int j=0;j<k;j++){
			S += (long long)d[j]%m;
			if(d[j]%m==0)S+=m;
		}
		x += S * ((n-1)/k);
		for(int j=0;j<(n-1)%k;j++){
			x += (long long)d[j]%m;
			if(d[j]%m==0)x+=m;
		}
		
		cout<<n-1-x/m<<endl;
	}
	
	return 0;
}
