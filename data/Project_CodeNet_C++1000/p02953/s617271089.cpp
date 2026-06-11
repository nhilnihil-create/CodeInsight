#include<bits/stdc++.h>
using namespace std;
#define LL long long

int main(){
	// sengen
	int n;
	// nyuryoku
	cin >> n;
	LL h[n];
	for(int i=0;i<n;i++){
		cin >> h[i];
	}
	// keisan
	for(int i=1;i<n;i++){
		if(h[i] > h[i-1]){
			h[i] = h[i] -1;
		}
	}
	// syutsuryoku
	for(int i=0;i<n-1;i++){
		if(h[i] > h[i+1]){
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
}