#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	double num;
	cin>>num;
	double side=num/3;
    double ans=side*side*side;
	cout<<fixed<<setprecision(8)<<ans;	
	return 0;
}