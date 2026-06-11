#include <bits/stdc++.h>
using namespace std;

int main(){
	int a, b, i, mi, mx;
	cin >> a >> b;
	
	mi = min(a, b);
	mx = max(a, b);
	
	for(i=mi; i<=mx; i++){
		if(abs(a - i) == abs(b - i)){
			cout << i << endl ;
			return 0;
		}
	}
	cout << "IMPOSSIBLE" << endl ;
}
