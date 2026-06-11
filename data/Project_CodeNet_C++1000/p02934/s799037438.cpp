#include<bits/stdc++.h>
using namespace std;

int main(){
	// sengen
	int n;
	// nyuryoku
	cin >> n;
	int a[n];
	double sum = 0;
	for(int i=0;i<n;i++){
		cin >> a[i];
		sum += (double)1/a[i];
	}
	// keisan
	printf("%lf",(double)1/sum);
	// syutsuryoku
}