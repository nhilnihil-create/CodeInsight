#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
#define ll long long int
#define ld long double

int main()
{
	ll l;
	cin>>l;
	ld d;
	d=l/3.0;
	d=d*d*d;
	cout<<fixed<<setprecision(12)<<d<<endl;

	return 0;
}