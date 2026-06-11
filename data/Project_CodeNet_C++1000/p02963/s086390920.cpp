#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll s;
	cin >> s;
	ll a = s/1000000000;
	ll b = s%1000000000;
	//if(b==0)b=1000000000;
	if(s==1000000000000000000)cout<<0<<' '<<0<<' '<<1000000000<<' '<<0<<' '<<0<<' '<<1000000000<<endl;
	else cout<<0<<' '<<0<<' '<<1000000000<<' '<<1<<' '<<(1000000000-b)<<' '<<a+1<<endl;
	return 0;
}
