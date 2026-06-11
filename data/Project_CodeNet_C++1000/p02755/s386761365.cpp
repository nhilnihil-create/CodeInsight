#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;



ll a, b;
int main(){
	cin >> a >> b;
	
	for ( int i = b*10; i < b*10+9; i++ ){
		if ( (i*8)/100 == a ){
			cout << i << endl;
			return 0;
		}
	}
	
	cout << -1 << endl;
	
	return 0;
}

