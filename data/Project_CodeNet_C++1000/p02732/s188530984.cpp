#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 2e5+10;
int N;
int a[MAX_N];

void solve()
{
	map<int,int> cnt;
	for(int i=1;i<=N;++i) cnt[a[i]]++;
	ll tot = 0;
	for(auto p : cnt) tot += 1LL*(p.second)*(p.second-1)/2;
	for(int i=1;i<=N;++i){
		cout<<tot-(cnt[a[i]]-1)<<'\n';
	}
}

int main()
{
	cin >> N;
	for(int i=1;i<=N;++i) cin >> a[i];
	solve();
	return 0;
}