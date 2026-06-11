#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int N;


int main(){
	cin >> N;
	vector<int> a(N+1);
	vector<int> b(N+1);
	
	for ( int i = 1; i <= N; i++ ){
		cin >> a[i];
	}
	
	int ball = 0;
	for ( int i = N; i >= 1; i-- ){ // 後ろからだと一意に決まる
		int bsum = 0;
		for ( int j = i; j <= N; j += i )
			bsum += b[j];
		b[i] = a[i] ^ (bsum & 1);
		ball += b[i];
	}
	
	cout << ball << endl;
	for ( int i = 1; i <= N; i++ )
		if ( b[i] )
			cout << i << endl;
	
	return 0;
}

