#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
	int N;
	cin >> N;
	int sum = 0;
	for(int i = 1; i <= N; i++){
		int a;
		cin >> a;
		if(i%2 && a%2){
			++sum;
		}
	}
	cout << sum << endl;

 
	return 0;
}