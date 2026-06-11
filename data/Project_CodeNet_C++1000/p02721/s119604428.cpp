#include<bits/stdc++.h>
using namespace std;
vector<int> f,b;
int n,k,c;
string s;
int main()
{
	cin>>n>>k>>c>>s;
	int last=-1e9;
	for(int i=1;i<=n;i++)
	{
		if(s[i-1]=='o'&&last+c<i)
		{
			last=i;
			f.push_back(i);
		}
		if(f.size()==k)
			break;
	}
	int stock=1e9;
	for(int i=n;i>=1;i--)
	{
		if(s[i-1]=='o'&&stock>=c)
		{
			b.push_back(i);
			stock=0; 
		}	
		else
			stock++;
		if(b.size()==k)
			break;
	}
	reverse(b.begin(),b.end());
	for(int i=0;i<k;i++)
		if(b[i]==f[i])
			cout<<f[i]<<endl;
	return 0;
}