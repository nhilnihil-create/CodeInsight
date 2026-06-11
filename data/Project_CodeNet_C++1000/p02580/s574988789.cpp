#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
const int N=3e5+5;
int x,y,a[N],b[N],p1,p2,i,j,m;
set<pi> st;
int main()
{
	cin>>x>>y>>m;
	vector<int> l,r;
	for(i=1;i<=m;i++)
	{
		cin>>x>>y;
		st.insert(make_pair(x,y));
		a[x]++;
		b[y]++;
		if(a[x]>p1)
		{
			l.clear();
			p1=a[x];
		}
		if(a[x]==p1)
			l.push_back(x);
		if(b[y]>p2)
		{
			r.clear();
			p2=b[y];
		}
		if(b[y]==p2)
			r.push_back(y);
	}
	for(i=0;i<l.size();i++)
		for(j=0;j<r.size();j++)
			if(st.find(make_pair(l[i],r[j]))==st.end())
			{
				cout<<p1+p2<<endl;
				return 0;
			}
	cout<<p1+p2-1<<endl;
	return 0;
}