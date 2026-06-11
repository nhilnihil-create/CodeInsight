#include<bits/stdc++.h>
using namespace std;
int main()
{
	int q,w;
	cin>>q;
	string a;
	cin>>a;
	int s=a.size();
	if(s<=q) cout<<a;
	else 
	{
		for(w=0;w<q;w++)
			cout<<a[w];
		cout<<"...";
	}
}