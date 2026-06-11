

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
		
	ll a,b,n;
	cin >> a>> b>>n;
	// for(int i=0;i<=n;i++){
	// 	cout << "i:" << i << " " << (a*i)/b - a*(i/b) << endl;
	// }

	if(n>=b){
		// cout << "hi\n";
		cout << ( (a*(b-1)) /b) - a*( (b-1)/b ) << endl;
	}else{
		cout << (a*n)/b - a*(n/b) << endl;
	}

	return 0;
}