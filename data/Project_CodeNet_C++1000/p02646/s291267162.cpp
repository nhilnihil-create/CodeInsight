#include<bits/stdc++.h>
using namespace std;

int main(){
	long long a,v,b,w,t,ans;
	cin>>a>>v>>b>>w>>t;
	if(v-w>0)
	{
		ans=(v-w)*t;
		if(ans>=abs(a-b))
		{
			cout<<"YES"<<endl; 
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
	else
	{
		cout<<"NO"<<endl;
	}
	return 0;
}