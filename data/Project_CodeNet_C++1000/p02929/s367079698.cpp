#include <iostream>
using namespace std;

#define MOD 1000000007

main(){
	long long n,k,ans;
	string s;
	cin>>n>>s;
	k = 0;
	ans = 1;
	for(int i=0;i<2*n;i++){
		if(i > 0 && i <= n)
			ans *= i;
		ans %= MOD;
		if(s[i] == 'B')
			if(k%2 == 0)
				k++;
			else
				ans *= k--;
		else
			if(k == 0)
				k = MOD;
			else if(k%2 == 0)
				ans *= k--;
			else
				k++;
		ans %= MOD;
	}
	if(k != 0)
		ans = 0;
	cout<<ans;
}