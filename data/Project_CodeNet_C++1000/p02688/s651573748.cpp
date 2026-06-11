#include<iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,k;
	cin >> n >> k;
	int freq[n] = {0};
	for(int i=0; i<k; i++){
		int d;
		cin >> d;
		for(int i=0; i<d; i++){
			int snuke;
			cin >> snuke;
			freq[snuke-1]++;
		}
	}
	
	int ans = 0;
	for(int i=0; i<n; i++){
		if(freq[i]==0) ans++;
	}
	cout << ans;
	return 0;
}