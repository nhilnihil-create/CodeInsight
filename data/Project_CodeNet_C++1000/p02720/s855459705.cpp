/**   
 *   Author:    @glaucoacassioc
 *   Created on 11.09.2020, 15:32:16
**/
#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
vector<vii> AdjList;

vi pai, color, dist, ts;
ll vals[1000002];
ll maxnr = 400000000;
set<ll> s;
void bkt(ll x)
{
	if(s.find(x) != s.end())
		return;

	s.insert(x);
	if(x >= maxnr)
		return;

	if(x == 0)
		for(int i=1; i<=9; i++)
			bkt(i);	
	else
	{
		int lst = x%10;
		if(lst > 0)
			bkt(x*10 + (lst-1));
		bkt(x*10 + lst);
		if(lst < 9)
			bkt(x*10 + (lst+1));
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int k;

	cin >> k;
	bkt(0);
	while(k)
	{
		s.erase(s.begin());
		--k;
	}
	cout << *s.begin() << endl;
	return 0;
}             