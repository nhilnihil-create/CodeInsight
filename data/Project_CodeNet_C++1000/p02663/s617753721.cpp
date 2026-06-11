#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int h1,m1,h2,m2,k,h,m;
	cin>>h1>>m1>>h2>>m2>>k;
	h=h2-h1;
	m=m2-m1;
	if(m<0)
	{
		h--;
		m=60+m;
	}
	cout<<h*60+m-k;
	return 0;
}