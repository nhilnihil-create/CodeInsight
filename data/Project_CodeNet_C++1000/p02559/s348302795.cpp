#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int,int> P;

int main()
{
	int N,Q;
	cin >> N >> Q;
	fenwick_tree<long long> fw(N);
	rep(i,N)
	{
		ll a;
		cin >> a;
		fw.add(i,a);
	}
	rep(i,Q)
	{
		ll a,b,c;
		cin >> a >> b >> c;
		if (a == 1)
		{
			cout << fw.sum(b,c) << endl;
		}
		else
		{
			fw.add(b,c);
		}
	}
	return 0;
}