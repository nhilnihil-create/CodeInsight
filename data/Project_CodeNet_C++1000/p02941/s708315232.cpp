#include<bits/stdc++.h>
#define ii pair<int,int>
#define mp make_pair
#define int long long int
using namespace std;

int32_t main(){
	int n,c=0;
	cin>>n;
	vector<int> a(n),b(n);
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)cin>>b[i];
	
	set<ii> data;
	for(int i=0;i<n;i++){
		data.insert(mp(b[i],i));
	}
	while(!data.empty()){
		int j=data.rbegin()->second;
		data.erase(--data.end());
		int q=b[(j+1)%n]+b[(j-1+n)%n];
		if((b[j]-a[j])%q==0){
			c+=(b[j]-a[j])/q;
			b[j]=a[j];
		}
		else{
			if(b[j]<q){cout<<-1;return 0;}
			c+=b[j]/q;
			b[j]%=q;
			if(b[j]<a[j]){cout<<-1;return 0;}
			data.insert(mp(b[j],j));
		}
	}
	cout<<c;
}
