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
	
	long long n;
	cin >> n;
	long long mx = n;
	
	if(n == 1){
		cout << 0 << endl;
		return 0;
	}
	
	long long ans = 0;
	for(long long i = 2; i * i <= n; i++){
		long long cnt = 0;
		if(n % i == 0){
			while(n % i == 0){
				n /= i;
				cnt++;
			}
			for(int j = 1; j <= cnt; j++){
				cnt -= j;
				ans++;
			}
		}
	}
	if(n > 1)ans++;
	cout << ans << endl;
	return 0;
}
 
