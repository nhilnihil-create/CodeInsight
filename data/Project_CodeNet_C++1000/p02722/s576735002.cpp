#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long int

main() {
	int n;
	cin>>n;
	vector<int>f;
	f.pb(n);
	for(int i=2; i*i<=n; i++){
		if(n%i==0 && i*i!=n){
			f.pb(i);
			f.pb(n/i);
			continue;
		}
		if(i*i==n){
			f.pb(i);
		}
	}
	int val=n-1;
	vector<int>f2;
	f2.pb(val);
	for(int i=2; i*i<=val; i++){
		if(val%i==0 && i*i!=val){
			f2.pb(i);
			f2.pb(val/i);
			continue;
		}
		if(i*i==val){
			f2.pb(i);
		}
	}
	vector<int>fin;
	for(auto u:f){
		int num=n;
		while(num%u==0){
			num=num/u;
		}
		num=num%u;
		if(num==1){
			fin.pb(u);
		}
	}
	for(auto u:f2){
		if(n%u!=0){
			fin.pb(u);
		}
	}
	cout<<fin.size();
	return 0;
}