#include <bits/stdc++.h>
 
using namespace std;
typedef long long int lli;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef pair <lli,lli> pii;
#define ff first
#define ss second
#define mod 1000000007
#define pb push_back
#define EPS 1e-6

inline lli moduloMultiplication(lli x, lli y) {
	return (x%mod * 1LL * y%mod) % mod;
}

 
int main(){
	fast;
	string s;
	cin>>s;
	int carry = 0, ans = 0;
	for(int i = s.size() - 1; i >= 0; i--)
	{
		int val = s[i] - '0';
		val += carry;
		carry = val / 10;
		val %= 10;
		if(val >= 6)
		{
			ans += (10 - val);
			carry = 1;
		}
		else if(val == 5)
		{
			if(i - 1 >= 0 && s[i - 1] >= '5')
			{
				ans += (10 - val);
				carry = 1;
			}
			else
				ans += val;
		}
		else
			ans += val;
	}	
	cout << ans + carry<<"\n";
	return 0;
}