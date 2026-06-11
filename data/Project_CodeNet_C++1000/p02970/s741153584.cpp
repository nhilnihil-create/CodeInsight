#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int main()
{
		ios_base::sync_with_stdio(false);
	cin.tie(NULL);
int n,d;
cin>>n>>d;
int l=n%(2*d+1);
int p=n/((2*d)+1);
if(l!=0)
{
	cout<<p+1<<endl;
}
else
{
	cout<<p<<endl;
}
}

