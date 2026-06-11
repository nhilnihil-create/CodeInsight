#include<bits/stdc++.h>
using namespace std;
#define int     long long
#define F       first
#define S       second
#define _READ   freopen("input.txt","r", stdin);
#define _FAST   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve()
{
	int x,y,a,b,c;
	cin>>x>>y>>a>>b>>c;
	deque<int> p(a),q(b),r(c);
	for(auto &i:p)
		cin>>i;
	for(auto &i:q)
		cin>>i;
	for(auto &i:r)
		cin>>i;
	sort(p.rbegin(),p.rend());
	sort(q.rbegin(),q.rend());
	sort(r.rbegin(),r.rend());
	while(p.size()!=x)
		p.pop_back();
	while(q.size()!=y)
		q.pop_back();
	for(auto &i:p)
		r.push_back(i);
	for(auto &i:q)
		r.push_back(i);
	sort(r.rbegin(),r.rend());
	int i=0,ans=0;
	while(i!=x+y)
	{
		ans+=r.front();
		r.pop_front();
		i++;
	}
	cout<<ans;
}
int32_t main()
{
	// vector<int> l={0,0,2,2,2,2,3};
	// auto it=lower_bound(l.begin(),l.end(),1);
	// l.insert(it,1);
	// for(auto i:l)
	// 	cout<<i<<" ";
	// cout<<"\n";
	// return 0;
    //_READ
	_FAST
    int t;
    t=1;
    while(t--)
        solve();
    return 0;
}
/*
===FOR N-Dimensional Vector===
https://codeforces.com/blog/entry/76149
g++ -std=c++17 -Wshadow -Wall -g -fsanitize=address -fsanitize=undefined a.cpp -o a -D_GLIBCXX_DEBUG
*/
