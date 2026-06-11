#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>
#include<queue>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<long long> a(n);
	for(int i = 0; i < n; i++)cin >> a[i];
	sort(a.begin() , a.end());
	
	if(a[0] == 0){
		cout << 0 << endl;
		return 0;
	}
	
	long long mx = pow(10,18);
	
	long long ans = 1;
	for(int i = 0; i < n; i++){
		if(ans > (mx / a[i]) || ans * a[i] > mx){
			cout << -1 << endl;
			return 0;
		}
		//cout << i << " : " << ans << " : " << (mx / a[i]) << endl;
		ans *= a[i];
	}
	cout << ans << endl;
	return 0;
}
 