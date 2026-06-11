#include<bits/stdc++.h>
using namespace std;

long long M, D;

bool check(int m, int d){
	int d1 = d/10;
	int d2 = d%10;
	return d1>1 && d2>1 && m == d1 * d2;
}

int main(){
	cin >> M >> D;

	long ans = 0;
	for(int m = 1; m <= M; m++){
		for(int d = 1; d <= D; d++){
			if(check(m, d)){
				ans++;
			}
		}
	}
	cout << ans << endl;
}