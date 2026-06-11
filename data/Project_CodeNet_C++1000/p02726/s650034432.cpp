#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;


ll n, x, y;

int main(){
	cin >> n >> x >> y;
	x--;
	y--;
	vector<int> h(n);
	
	
	for ( int i = 0; i < n; i++ ){
		for ( int j = i+1; j < n; j++ ){
			int dix = abs(i-x);
			int djy = abs(j-y);
			int distance = min(j-i, dix+djy+1);
			h[distance]++;
		}
	}
	
	for ( int k = 1; k < n; k++ ){
		cout << h[k] << " ";
	}
	
	cout << endl;
	
	return 0;
}


