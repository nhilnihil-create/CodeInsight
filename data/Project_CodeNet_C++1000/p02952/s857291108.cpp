#include<bits/stdc++.h>
using namespace std;
#define LL long long

int main(){
	// sengen
	int n;
	// nyuryoku
	cin >> n;
	// keisan
	int count = 0;
	if(n > 9){
		count += 9;
	}else{
		count += n;
	}
	if(n > 999){
		count += 900;
	}else{
		if(n > 99){
			count += n - 100 + 1;
		}
	}
	if(n > 99999){
		count += 90000;
	}else{
		if(n > 9999){
			count += n - 9999;
		}
	}
	// syutsuryoku
	cout << count << endl;
}
