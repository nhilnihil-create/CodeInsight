#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int> ve[N];
priority_queue<int> qe;
int main()
{
	int n,m,sum=0;
	cin>>n>>m;
	int a,b;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		if(m-a+1>0)ve[m-a+1].push_back(b);
	}
	for(int i=m;i>0;i--)
	{
		for(int j=0;j<ve[i].size();j++)qe.push(ve[i][j]);
		if(qe.size())
		{
			sum+=qe.top();qe.pop();
		}//djgldgsldgjdl
	}cout<<sum;
}