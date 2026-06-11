#include<bits/stdc++.h>
using namespace std;
#define LL long long

int main(){
	// sengen
	int n;
	// nyuryoku
	cin >> n;
	int w[n];
	int right = 0,left = 0;
	for(int i=0;i<n;i++){
		cin >> w[i];
		right += w[i];
	}
	int ans = right;
	// keisan
	for(int i=0;i<n-1;i++){
		left += w[i];
		right -= w[i];
		ans = min(ans,abs(right - left));
	}
	// syutsuryoku
	cout << ans << endl;
}