#include<iostream>
#include<set>
#include<vector>
using namespace std;
const int N=3e5+7;
vector<int>vecc,vecr;
int mxr,mxc,row[N],col[N];
set<pair<int,int> >st;

int32_t main()
{
	int h,w,m;
	scanf("%d%d%d",&h,&w,&m);
	for(int i=0;i<m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		row[x]++;
		col[y]++;
		if(mxr<row[x])
		{
			mxr=row[x];
			vecr.clear();
		}
		if(mxr==row[x])
			vecr.push_back(x);

		if(mxc<col[y])
		{
			mxc=col[y];
			vecc.clear();
		}
		if(mxc==col[y])
			vecc.push_back(y);
		st.insert({x,y});
	}
	int _is=1;
	for(int i=0;i<vecr.size();i++)
	{
		int x=vecr[i];
		for(int j=0;j<vecc.size();j++)
		{
			int y=vecc[j];
			if(st.count({x,y})==0)
			{
				_is=0;
				break;
			}
		}
		if(_is==0)
			break;
	}
	printf("%d\n",mxr+mxc-_is);
}
