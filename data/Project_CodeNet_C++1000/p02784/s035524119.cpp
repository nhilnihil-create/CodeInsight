#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main ()
{
	ll h,n,a;
	cin>>h>>n;
	ll ans=0;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		ans+=a;
		
	}
	if(ans>=h) {
		cout<<"Yes"<<endl;
	}
	
	else  cout<<"No"<<endl;
	
	


}

