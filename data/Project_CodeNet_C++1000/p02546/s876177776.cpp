#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sync ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD  1000000007 
int powm(int base,int exp,int mod=MOD) {int ans=1;while(exp){if(exp&1) ans=(ans*base)%mod;exp>>=1,base=(base*base)%mod;}return ans;}
int32_t main()
{
	string s;
	cin>>s;
	if(s.back() != 's')
		s.push_back('s');
	else{
		s.push_back('e');
		s.push_back('s');
	}
	cout<<s<<endl;
}