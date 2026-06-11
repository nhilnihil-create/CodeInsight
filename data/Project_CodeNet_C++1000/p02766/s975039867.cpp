#include<iostream>
using namespace std;

int base_change(int n, int k){
	int ans = 0;
	while(n>0){
		ans++;
		n = n/k;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,k;
	cin >> n >> k;
	cout << base_change(n,k);
	return 0;
	
}