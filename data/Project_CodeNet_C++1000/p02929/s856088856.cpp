#include <iostream>
#include <algorithm>
#include <string>
#include <numeric>
#include <vector>
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int
#define MAX 1000000007

using namespace std;


int main(void){
	int n;
	cin >> n;
	string s;
	cin >> s;
	if(s[0] == 'W'){
		cout << 0 << endl;
		return 0;
	}
	int cnt=1;
	ll ans=1;
	for(int i=1;i<2*n;i++){
		if(cnt%2 == 1){
			if(s[i] == 'W'){
				cnt++;
			}
			else{
				ans*=cnt;
				cnt--;
			}
		}
		else{
			if(s[i] == 'W'){
				ans*=cnt;
				cnt--;
			}
			else{
				cnt++;
			}
		}
		ans %= MAX;
	}

	for(int i=n;i>1;i--){
		ans *= i;
		ans %= MAX;
	}

	if(cnt == 0)cout << ans << endl;
	else cout << 0 << endl;

	return 0;

}
