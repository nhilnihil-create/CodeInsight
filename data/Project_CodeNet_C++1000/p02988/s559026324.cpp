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

int main()
{
	int N;
	vector<int>p;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		int t;
		cin>>t;
		p.push_back(t);
	}
	int r=0;
	for(int i=1;i<=N-2;i++)
	{
		if((p[i-1]<p[i]&&p[i]<p[i+1])||(p[i+1]<p[i]&&p[i]<p[i-1]))r++;
	}
	cout<<r<<endl;

}