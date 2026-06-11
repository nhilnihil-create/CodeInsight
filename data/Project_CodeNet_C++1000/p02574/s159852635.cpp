#include<bits/stdc++.h>
using namespace std;

int factors[1000003];
bool flag = false;

void func(int n){
	if(flag) return;
	for(int i=1; i*i<=n; i++){
		if(n%i==0){
			int x = i;
			int y = n/i;
			
			if(x==y){
				x = i;
				y = 1;
			}
			if(x!=1){
				if(factors[x]){
					flag = true;
					return;
				}
				factors[x]++;
			}
			if(y!=1){
				if(factors[y]){
					flag = true;
					return;
				}
				factors[y]++;
			}
		}
	}
}

main(){
	int n; cin>>n;
	int a[n];
	for(auto &it : a) cin>>it;
	
	int gcd = a[0];
	func(a[0]);
	
	for(int i=1; i<n; i++){
		func(a[i]);
		gcd = __gcd(gcd,a[i]);
	}
	if(!flag) cout<<"pairwise coprime";
	else if(gcd==1) cout<<"setwise coprime";
	else cout<<"not coprime";
}