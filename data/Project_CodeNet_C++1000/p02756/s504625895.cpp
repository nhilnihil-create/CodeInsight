#include<bits/stdc++.h>
using namespace std;
#define left l
#define right r
char c[300005];
char v[1000005];
int n;
int l,r;
void qian(char x)
{
    v[--l] = x;
}
void hou(char x)
{
	v[r++]=x;
}
int main()
{
	cin>>c;
	n=strlen(c);
	int t;
	cin>>t;
	int cnt=0;
	l = 200005;
	r =200005;
	for(int i=0;i<n;++i)
	    v [ l + i] =  c [ i ],r ++ ; 
	for(int k=1;k<=t;++k)
	{
		int s;
		cin>>s;
		if(s==1) ++cnt;
		else
		{
			int q;
			cin>>q;
			char x;
			cin>>x;
			if(q==1)
			{
				if(cnt%2)
					hou(x);
				else
					qian(x);
			}
			else 
			{
				if(cnt%2)
				   qian(x);
				else
					hou(x);
			}
			++n;
		}
	}
	if(!(cnt%2))
	    for(int i=left;i<right;++i)
	       cout<<v[i];
	else
	    for(int i=right-1;i>=left;--i)
	       cout<<v[i];
	cout<<endl;
	return 0;
 } 