#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	long long int a,b,c,d,ar[10];
	cin>>a>>b>>c>>d;
	ar[0]=a*d;
	ar[1]=a*c;
	ar[2]=b*c;
	ar[3]=b*d;
	sort(ar,ar+4);
	cout<<ar[3]<<endl;
	return 0;
}