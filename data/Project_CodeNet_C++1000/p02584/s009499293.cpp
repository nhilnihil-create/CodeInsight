#include<bits/stdc++.h>
#define int long long int
using namespace std;
#define pb push_back
int32_t main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int x,k,d;cin >> x >> k >> d;
	if(x==0){
		if(k&1)	cout << d;
		else	cout << 0;
		return 0;
	}
	x=abs(x);
	int a=x%d;int b=x/d;
	if(b>=k){
		int ans=x;
		ans-=(k*d);
		cout << abs(ans);
		return 0;
	}
	k-=b;
	if(k&1)	cout << abs(d-a);
	else	cout << abs(a);


	return 0;
}
