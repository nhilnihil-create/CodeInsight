#include <iostream>

using namespace std;

int main()
{
	int h1,m1,h2,m2,k;
	cin>>h1>>m1>>h2>>m2>>k;
	int ans = h2*60+m2;
	ans -= h1*60+m1;
	ans -= k;
	cout<<ans<<endl;
	return 0;
}