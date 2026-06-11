#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 2e5+10;
int N;
int A[MAX_N];
int cnt[MAX_N];

void solve()
{
	for(int i=2;i<=N;++i){
		cnt[A[i]]++;
	}
	for(int i=1;i<=N;++i)cout << cnt[i] << '\n';
}

int main()
{
	cin >> N;
	for(int i=2;i<=N;++i) cin>> A[i];
	solve();
	return 0;
}