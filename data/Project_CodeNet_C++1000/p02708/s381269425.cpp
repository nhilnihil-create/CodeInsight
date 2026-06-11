#include<bits/stdc++.h>
using namespace std;

const double PI = 3.14159;
const int modi = 1e9+7;
int main(){
	int n,k;
	cin >> n >> k;
	long long pref[n+1],suff[n+1];
	pref[0] = 0;
	suff[n]=n;
	long long ans = 0;
	for(long long i =1;i<=n;i++){
		pref[i]=pref[i-1]+i;
		suff[n-i] = suff[n-i+1] + (n-i);
	}

	for(int i =k;i<=n;i++){
		ans = ans+(suff[n-i+1]- pref[i-1]+1);
		ans%=modi;
		// cout << ans << endl;
	}
 	ans++;
 	ans%=modi;
	cout << ans << endl;

}