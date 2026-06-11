#include<bits/stdc++.h> 
using namespace std;

typedef long long ll;

int main(){
	ll n;
	cin >> n;
	int ans = 0, cnt = 0;
	for(int i = 2; i< 1000010; i++){
		cnt = 0;
		while(n % i == 0){
			n /= i;
			cnt++;
		}
		for(int j = 1; j<10000; j++){
			if(cnt-j >= 0){
				cnt -= j;
				ans++;
			}
			else{
				break;
			}
		}
	}
	if(n > 1){
		ans ++;
	}
	cout << ans;
	return 0;
}