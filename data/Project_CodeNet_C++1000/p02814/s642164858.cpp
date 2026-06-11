#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	
	int n,m; cin>>n>>m;
	vector<ll> a(n);
	for(auto &i:a) {
		cin>>i;
		i/=2;
	}
	ll l = a.at(0);
	for(int i=1; i<n; i++){
		
		if(l%a.at(i)==0&&(l/a.at(i))%2==0){
			cout << 0 << endl;
			return 0;
		}
		if(a.at(i)%l==0&&(a.at(i)/l)%2==0){
			cout << 0 << endl;
			return 0;
		}
		l = a.at(i)/__gcd(a.at(i),l)*l;
		if(l>m){
			cout << 0 << endl;
			return 0;
		}
	}
	cout << (m/l+1)/2 << endl;
	
	
}
