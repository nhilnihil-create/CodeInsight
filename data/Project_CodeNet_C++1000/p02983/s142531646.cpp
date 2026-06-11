#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll L, R;



int main(){
	cin >> L >> R;
	
	ll result = 2019;
	for ( ll i = L; i < R && i < L+2019; i++ ){
		for ( ll j = i+1; j <= R && j < i+1+2019; j++ ){
			result = min( result, (i*j) % 2019 );
		}
	}
	
	
	cout << result << endl;
	
	
	return 0;
}

