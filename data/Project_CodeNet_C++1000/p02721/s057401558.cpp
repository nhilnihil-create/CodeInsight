#include <bits/stdc++.h>
#define ll long long
#define MAXN 200010
using namespace std;
#define MAXN 200010
int N, K, C;
string S;
pair<int, int> l[MAXN];
pair<int, int> r[MAXN];

int main()
{
	cin>>N>>K>>C;
	cin>>S;
	l[0] = make_pair(0, 300000);
	int rest = 300000;
	int work = 0;
	for(int i = 0; i < N - 1; ++i)
	{
		if(S[i] == 'o' && rest >= C)
		{
				work++;
				rest = 0;
		}
		else
		{
				rest++;
		}
		l[i+1] = make_pair(work, rest);
	}
	rest = 300000;
	work = 0;
	r[N-1] = make_pair(work, rest);
	for(int i = N - 1; i > 0; --i)
	{
			if(S[i] == 'o' && rest >= C)
			{
				work++;
				rest = 0;
			}
			else
			{
				rest++;
			}
			r[i-1] = make_pair(work, rest);
	} 
	for(int i = 0; i < N; ++i)
	{
			if(S[i] == 'x')
				continue;
			int w = l[i].first + r[i].first;
			int re = l[i].second + r[i].second;
			if(w < K)
			{
				cout<<i+1<<endl;
			}
	}
}
