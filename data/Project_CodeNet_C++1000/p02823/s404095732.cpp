#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

int main(){
	
	ll n,a,b; cin>>n>>a>>b;
	if(!(abs(a-b)%2)){
		cout << abs(a-b)/2 << endl;
	}
	else{
		if(a-1<n-b){
			cout << a+(b-a-1)/2 << endl;
		}
		else{
			cout << n-b+1+(n-(a+n-b+1))/2 << endl;
		}
	}
	
	
}

