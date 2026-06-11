#include <bits/stdc++.h>

#define all(x) (x).begin(),(x).end()
#define MOD 1000000007
using namespace std;

int main(){
	int x, y, a, b, c;	cin >> x >> y >> a >> b >> c;
	long long int p[a];
	for( int i = 0; i < a; i++ ){
		cin >> p[i];
	}
	long long int q[b];
	for( int i = 0; i < b; i++ ){
		cin >> q[i];
	}
	long long int r[c];
	for( int i = 0; i < c; i++ ){
		cin >> r[i];
	}
	vector<long long int> eat;
	long long int ans = 0;
	int cur = 0;

	sort( p, p + a, greater<long long int>() );
	sort( q, q + b, greater<long long int>() );
	sort( r, r + c, greater<long long int>() );

	for( int i = 0; i < x; i++ ){
		eat.push_back( p[i] );
	}
	for( int i = 0; i < y; i++ ){
		eat.push_back( q[i] );
	}
	sort( all(eat) );

	for( int i = 0; i < x + y; i++ ){
		if( eat[i] < r[cur] && cur < c ){
			eat[i] = r[cur];
			cur++;
		}
	}

	for( int i = 0; i < x + y; i++ ){
		ans += eat[i];
	}

	cout << ans << endl;

	return 0;
}
