#include<bits/stdc++.h>
using namespace std;
#define LL long long

int main(){
	// sengen
	int n;
	// nyuryoku
	cin >> n;
	int a[n];
	int b[1000001] = {};
	int count = 0;
	for(int i=0;i<n;i++){
		cin >> a[i];
		b[a[i]]++;
	}
	int c = 1;
	// keisan
	int ans = 1;
	for(int i=2;i<=1000000;i++){
		int tmp = 0;
		for(int j=1;i*j<=1000000;j++){
			tmp += b[i*j];
		}
		if(tmp > 1){
			c = 0;
		}
		ans = max(ans,tmp);
	}
	if(c){
		cout << "pairwise coprime" << endl;
	}else if(ans == n){
		cout << "not coprime" << endl;
	}else{
		cout << "setwise coprime" << endl;
	}
	// syutsuryoku
}