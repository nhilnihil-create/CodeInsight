#include <bits/stdc++.h>

#define lli long long int
#define REP(i,s,n) for(lli i=s;i<n;i++)
#define MOD 1000000007

using namespace std;

lli factorial(lli n){
	lli ans = 1;
	while(n>1){
		ans *= n;
		ans %= MOD;
		n--;
	}
	return ans;
}


int main(){

	lli n;
	string s;
	cin>>n>>s;

	n *= 2;

	vector<bool> is_right(n);
	REP(i,0,n){
		if(i%2 == 0 && s[i] == 'W')is_right[i] = true;
		if(i%2==1 && s[i] == 'B')is_right[i] = true;
	}

	lli ans = 1;
	lli left_sum = 0;

	REP(i,0,n){
		if(is_right[i]){
			if(left_sum == 0){
				cout<<0<<endl;
				return 0;
			}
			ans *= left_sum;
			ans %= MOD;
			left_sum--;
		}else{
			left_sum++;
		}
	}
	if(left_sum)cout<<0<<endl;
	else cout<<ans*factorial(n/2)%MOD<<endl;

	return 0;



}