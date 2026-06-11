#include <iostream>
#include <string>
#include <unordered_map>
#include <stdio.h>
#include <list>
#include <vector>
#include <algorithm>
#include <stack>
#include <climits>
#include <cmath>
#include <map>
#include <queue>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

int main()
{
	int n;
	cin >> n;
	vector<int> A(n);
	rep(i,n)cin>>A[i];
	vector<int> anss;
	sort(ALL(A));
	stack<int> nS,pS;
	nS.push(A[0]);
	pS.push(A[A.size()-1]);
	for(int i=1;i<n-1;i++)
	{
		if(A[i]<0)nS.push(A[i]);
		else pS.push(A[i]);
	}
	int ans=-A[0];
	for(int i=1;i<n-1;i++)ans+=abs(A[i]);
	ans+=A[n-1];
	cout<<ans<<endl;
	while(pS.size()!=1)
	{
		cout<<nS.top()<<" "<<pS.top()<<endl;
		nS.top()-=pS.top();
		pS.pop();
	}
	while(!nS.empty())
	{
		cout<<pS.top()<<' '<<nS.top()<<endl;
		pS.top()-=nS.top();
		nS.pop();
	}


	return 0;
}