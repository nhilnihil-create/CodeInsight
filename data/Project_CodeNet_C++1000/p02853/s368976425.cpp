#include <bits/stdc++.h>
using namespace std;

#define endl '\n';
#define ll long long

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	ll int a,b,sum=0;
	cin >> a >> b;
	if(a==1) sum+=300000;
	else if(a==2) sum+=200000;
	else if(a==3) sum+=100000;
	if(b==1) sum+=300000;
	else if(b==2) sum+=200000;
	else if(b==3) sum+=100000;
	if(a==1 && b==1) sum+=400000;
	
	cout << sum << endl;
	
	return 0;
}