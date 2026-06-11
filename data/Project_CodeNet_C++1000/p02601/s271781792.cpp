#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int a,b,c,k,k1=0; cin >> a >> b >> c >> k;
	
	while (a >= b){
		b = b*2;
		k1++;
	}
	
	while (b >= c){
		c = c*2;
		k1++;
	}
	
	if (k1 <= k) cout << "Yes\n";
	else cout << "No\n";
	
	return 0;
}