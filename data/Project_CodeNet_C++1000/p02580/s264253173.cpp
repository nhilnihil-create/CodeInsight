#include <bits/stdc++.h>
using namespace std;

int h,w,m,hm[300050],wm[300050],p1,p2;
set<pair<int,int> > st;
vector<int> l,r;

int main()
{
	int x,y;
	cin>>h>>w>>m;
	
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		st.insert(make_pair(x,y));
		hm[x]++;
		wm[y]++;
		if(hm[x]>p1)
		{
			l.clear();
			p1=hm[x];
		}
		if(hm[x]==p1) l.push_back(x);
		if(wm[y]>p2)
		{
			r.clear();
			p2=wm[y];
		}
		if(wm[y]==p2) r.push_back(y);
	}
	
	for(int i=0;i<l.size();i++)
	   for(int j=0;j<r.size();j++)
	   {
	   	  if(st.find(make_pair(l[i],r[j]))==st.end())
	   	  {
	   	  	cout<<p1+p2;
	   	  	return 0;
		  }
	   }
	   
	cout<<p1+p2-1;
	
	return 0;
	
}