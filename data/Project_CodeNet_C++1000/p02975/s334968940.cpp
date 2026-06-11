#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

int main(){
	
	int n; cin>>n;
	int b{};
	for(int i=0; i<n; i++){
		int a; cin>>a;
		b ^= a;
	}
	if(!b) cout << "Yes" << endl;
	else cout << "No" << endl;
	
}

