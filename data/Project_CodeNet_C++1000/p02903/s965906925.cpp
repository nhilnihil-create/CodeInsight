#include<cstdio>
#include<cstdlib>
#include<string>
#include<cmath>
#include<cstdlib>
#include<climits>
#include<iostream>
#include<sstream>
#include<utility>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
#include<stack>
#include<functional>
#include<ios>
#include<iomanip>

using namespace std;
typedef long long ll;
typedef pair<int,int>P;

int H,W,A,B;

void dbg(vector<vector<int>> c)
{
	for(int i=0;i<c.size();i++)
	{
		for(int j=0;j<c[i].size();j++)
			cout<<c[i][j];
		cout<<endl;
	}
}

vector<vector<int>>fill(int rowOneCnt,int colOneCnt)
{
	vector<vector<int>>res;
	vector<int>colcnt(W,0);

	for(int i=0;i<H;i++)
	{
		int one=0;
		vector<int>row;
		for(int j=0;j<W;j++)
		{
			if(one<rowOneCnt&&colcnt[j]<colOneCnt)
			{
				row.push_back(1);
				one++;
				colcnt[j]++;
			}
			else
			{row.push_back(0);
			}
		}
		res.push_back(row);
	}
	return res;

}

bool check(vector<vector<int>> r)
{
	vector<int> rowOne(H,0),colOne(W,0);
	for(int i=0;i<H;i++)
		for(int j=0;j<W;j++)
		{
			if(r[i][j]==1)
			{
				rowOne[i]++;
				colOne[j]++;
			}
		}
	for(int i=0;i<rowOne.size();i++)
	{
		if(min(rowOne[i],W-rowOne[i])!=A)return false;
	}
	for(int i=0;i<colOne.size();i++)
	{
		if(min(colOne[i],H-colOne[i])!=B)return false;
	}
	return true;
}

int main()
{
	
	cin>>H>>W>>A>>B;
	vector<P>x={make_pair(A,B),
		make_pair(W-A,B),
		make_pair(A,H-B),
		make_pair(W-A,H-B)};
	for(P p : x)
	{
		auto r=fill(p.first,p.second);
		if(check(r))
		{
			dbg(r);
			return 0;
		}
	}
	cout<<"No"<<endl;
}