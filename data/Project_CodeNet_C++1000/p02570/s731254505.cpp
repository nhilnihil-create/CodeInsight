#include <bits/stdc++.h>
using namespace std;


int n,m,T;
int d,t,s;
int main()
{
	cin >> d >> t >> s;
	double ans = d*1.0/s;
	if(ans <= t*1.0)
	cout << "Yes"<<endl;
	else cout << "No"<<endl;
	return 0;
}