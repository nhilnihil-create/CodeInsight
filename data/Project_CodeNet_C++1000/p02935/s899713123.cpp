#include<bits/stdc++.h>
using namespace std;
#define LL long long

int main(){
	// sengen
	int n;
	// nyuryoku
	cin >> n;
	double v[n];
	for(int i=0;i<n;i++){
		cin >> v[i];
	}
	sort(v,v+n);
	double ans = 0;
	// keisan
	for(int i=0;i<n;i++){
		if(i == 0) continue;
		if(i == 1){
			ans = (v[0] + v[1])/2;
			continue;
		}
		ans = (v[i] + ans)/2;
	}
	// syutsuryoku
	printf("%lf",ans);
}