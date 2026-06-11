#include<bits/stdc++.h>
using namespace std;
#define LL long long

int main(){
	// sengen
	int n;
	// nyuryoku
	cin >> n;
	int a[n+1] = {};
	for(int i=0;i<n;i++){
		cin >> a[i+1];
	}
	int b[n+1] = {};
	int m = 0;
	for(int i=n;i>0;i--){
		int sum = 0;
		int j = 2;
		while(i*j <= n){
			sum += b[i*j];
			j++;
		}
		if(sum % 2 != a[i]){
			b[i]++;
			if(b[i] == 1){
				m++;
			}
		}
	}
	// keisan
	cout << m << endl;
	if(m){
		for(int i=1;i<=n;i++){
			if(b[i]){
				cout << i << ' ';
			}
		}
	}
	// syutsuryoku
}