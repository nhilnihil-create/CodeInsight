#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
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
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
typedef vector<vector<int>> MX;

const ll MOD=1e9+7;
const int INF = 100000000;

int main()
{
	int N,X,Y;
	cin>>N>>X>>Y;

	vector<vector<int>>v(N);
	for(int i=0;i<N-1;i++)
	{
		v[i].push_back(i+1);
		v[i+1].push_back(i);
	}
	v[X-1].push_back(Y-1);
	v[Y-1].push_back(X-1);


	vector<int> R=vector<int>(N+1,0);
	for(int s=0;s<N;s++)
	{
		queue<int>Q;
		Q.push(s);
		vector<int>d(N,INF);d[s]=0;
		while(!Q.empty())
		{
			int p=Q.front();Q.pop();
			for(int j=0;j<v[p].size();j++)
			{
				if(d[v[p][j]]>d[p]+1)
				{
					d[v[p][j]]=d[p]+1;
					Q.push(v[p][j]);

				}
			}
		}
		for(int i=0;i<N;i++)
			if(d[i]!=INF)R[d[i]]++;
	}

	for(int i=1;i<N;i++)
		cout<<R[i]/2<<endl;
}
