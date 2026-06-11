#include<bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin >> n;

	vector<int> a(n+1),b(n);

	for ( int i = 0; i < n + 1; i++){
		cin >> a[i];
	}

	for ( int i = 0; i < n; i++){
		cin >> b[i];
	}

	long long yoryoku = 0,cnt = 0;

	for ( int i = 0; i < n; i++){
		if ( a[i] >= yoryoku ){
			cnt += yoryoku;
            a[i] -= yoryoku;
			yoryoku = 0;		
		}else{
			cnt += a[i];
			yoryoku = 0;
			a[i] = 0;
		}
		if ( a[i] == 0 ){
			yoryoku = b[i];
			continue;
		}
		if ( a[i] >= b[i] ){
			cnt += b[i];
			yoryoku = 0;
		}else{
			cnt += a[i];
			yoryoku = b[i] - a[i];
		}
	}

	
	if ( a[n] >= yoryoku ){
		cnt += yoryoku;
	}else{
		cnt += a[n];
	}
		
	cout << cnt << endl;

	return 0;

}
