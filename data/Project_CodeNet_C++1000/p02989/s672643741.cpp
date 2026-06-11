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
vector<int>S;

int main()
{
	int N,res=0;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		int t;
		cin>>t;
		S.push_back(t);
	}
	sort(S.begin(),S.end());
	for(int i=0;i<=100000;i++)
	{
		int cnt=lower_bound(S.begin(),S.end(),i)-S.begin();
		if(cnt==N/2)res++;
	}
	cout<<res<<endl;
}