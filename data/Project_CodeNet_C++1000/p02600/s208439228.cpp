#include<bits/stdc++.h>
#define endl '\n'
#define int long long
 
using namespace std;
 
int32_t main ()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int x;
	cin>>x;
	if(x<600)cout<<"8"<<endl;
	else if(x<800)cout<<"7"<<endl;
	else if(x<1000)cout<<"6"<<endl;
	else if(x<1200)cout<<"5"<<endl;
	else if(x<1400)cout<<"4"<<endl;
	else if(x<1600)cout<<"3"<<endl;
	else if(x<1800)cout<<"2"<<endl;
	else if(x<2000)cout<<"1"<<endl;
	
	return 0;
}
