#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
int main(){
	ll n, ans = 1, cou = 0;
	string str;
	cin >> n >> str;
	for(int i = 0;i < str.size();i++){
		int now = ((cou % 2 == 0) + (str[i] == 'B')) % 2;
		if(now){
			ans = (ans * cou) % MOD;
			cou--;
		}
		else {
			cou++;
		}
		if(cou < 0){
			cout << 0 << endl;
			return 0;
		}
	}
	for(int i = 1;i <= n;i++){
		ans = (ans * i) % MOD;
	}
	cout << (cou == 0 ? ans : 0) << endl;
}
