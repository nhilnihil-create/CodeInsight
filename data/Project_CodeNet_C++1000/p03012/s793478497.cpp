#include<iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int w[n];
	int sum = 0;
	for(int i=0; i<n; i++){
		cin >> w[i];
		sum += w[i];
	}
	int sum1 = w[0]; int sum2 = sum-w[0];
	int mn = abs(sum1-sum2);
	int i=1;
	while(i<n){
		sum1 += w[i]; sum2 -= w[i];
		if(abs(sum1-sum2) < mn) mn = abs(sum1-sum2);
		i++;
	} 
	cout << mn;
	return 0;
}