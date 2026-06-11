#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
signed main(){
	int L, R, d;
	cin >> L >> R >> d;
	int sum = 0;
	for(int i = L; i <= R; i++){
		if(i%d == 0){
			++sum;
		}
	}
	cout << sum << endl;
 
	return 0;
}