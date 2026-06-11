#include<bits/stdc++.h>
using namespace std;
int main()
{
	int l,r,d;
	cin>>l>>r>>d;
	int lb =(l+d-1)/d;
	int rb = r/d;
	cout<<rb-lb+1<<"\n";
}