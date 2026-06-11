#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;



ll n, m;

int main(){
	cin >> n >> m;
	
	vector<int> v = {-1,-1,-1};
	for ( int i = 0; i < m; i++ ){
		int s, c;
		cin >> s >> c;
		s--;
		if ( s < n && (v[s] == -1 || v[s] == c) ){
			v[s] = c;
		}
		else {
			cout << -1 << endl;
			return 0;
		}
	}
	
	if ( n == 1 ){
		if ( v[0] == -1 )
			v[0] = 0;
		cout << v[0] << endl;
	}
	else {
		if ( v[0] == 0 ){
			cout << -1 << endl;
		}
		else {
			if ( v[0] == -1 ){
				v[0] = 1;
			}
			ll result = 0;
			
			for ( int i = 0; i < n; i++ ){
				result *= 10;
				if ( v[i] == -1 )
					v[i] = 0;
				result += v[i];
			}
			
			cout << result << endl;
		}
	}
	
	
	return 0;
}

