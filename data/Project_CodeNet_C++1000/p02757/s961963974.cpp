#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

int main(){
	
	int n,p; cin>>n>>p;
	string s; cin>>s;
	if(p==2||p==5){
		ll sum{};
		for(int i=0; i<n; i++){
			if((s.at(i)-'0')%p==0){
				sum += i+1;
			}
		}
		cout << sum << endl;
	}
	else{
		vector<ll> a(n+1);
		ll mul{1};
		for(int i=0; i<n; i++){
			a.at(i+1) = (a.at(i)+(s.at(n-i-1)-'0')*mul)%p;
			mul = mul*10%p;
		}
		map<int,ll> m;
		ll sum{};
		for(int i=0; i<n+1; i++){
			sum+=m[a.at(i)];
			m[a.at(i)]++;
		}
		cout << sum << endl;
	}
	
}
