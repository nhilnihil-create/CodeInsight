#include <iostream>

using namespace std;

int n;
int R[200000];
int dp1, dp2, rmax;

int main(void)
{
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> R[i];
	}
	
	for(int i=0;i<n-1;i++){
		if (i==0){
			dp1 = R[n-i-1]-R[n-i-2];
			rmax = R[n-i-1];
		}else{
			rmax = max(rmax, R[n-i-1]);
			dp1 = max(dp2, rmax-R[n-i-2]);
		}
		dp2 = dp1;
	}
	
	cout << dp1 << endl;
	return 0;
}