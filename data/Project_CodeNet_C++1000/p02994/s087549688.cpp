#include<bits/stdc++.h>
using namespace std;
#define LL long long

int main(){
	// sengen
	int n,l;
	// nyuryoku
	cin >> n >> l;
	int mi,ma;
	mi = l;
	ma = l + n -1;
	int sum = n*(mi + ma)/2;
	if(mi <= 0 && ma >= 0){
		cout << sum << endl;
	}else if(abs(mi) >= abs(ma)){
		cout << sum - ma << endl;
	}else{
		cout << sum - mi << endl;
	}
	// keisan

	// syutsuryoku
}