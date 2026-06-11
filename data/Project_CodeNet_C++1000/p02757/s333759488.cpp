#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
	int n, p;
	vector<ll> rem;
	ll ans = 0;
	string s;
	cin>>n>>p;
	cin>>s;
	if(p==2 || p==5){
		int cnt = 0;
		for(int i=0;i<n;i++){
			int digit = s[i]-'0';
			if(digit%p == 0){
				ans += (i+1);
			}
		}
	}
	else{
		reverse(s.begin(), s.end());
		rem.assign(p, 0);
		int cur_rem = 0, pw = 1;
		for(int i=0;i<n;i++){
			int digit = s[i]-'0';
			cur_rem = (pw*digit + cur_rem)%p;
			pw*=10;
			pw%=p;
			rem[cur_rem]++;
		}
		for(int i=0;i<p;i++){
			//cout<<i<<": "<<rem[i]<<"\n";
			ans += (rem[i]*(rem[i]-1))/2;
		}
		ans += rem[0];
	}
	cout<<ans<<"\n";
	return 0;
}