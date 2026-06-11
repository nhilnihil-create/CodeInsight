#include<iostream>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<unordered_set>
#include<unordered_map>
#define ll long long 
#define lowbit(x) (x)&(-x)
using namespace std;

const int maxn = 1e5 + 100;
int father[maxn];
int getfather(int x)
{
	if (x == father[x]) return x;
	else return father[x] = getfather(father[x]);
}

set<int> s;
int main()
{
	ios::sync_with_stdio(false);
	int N; int M; cin >> N >> M;
	for (int i = 1; i <= N; i++) father[i] = i;
	for (int i = 1; i <= M; i++)
	{
		int a; int b; cin >> a >> b;
		int fa = getfather(a);
		int fb = getfather(b);
		if (fa != fb) father[fa] = fb;
	}

	for (int i = 1; i <= N; i++)
		s.insert(getfather(i));

	cout <<s.size() - 1 << endl;
	return 0;
}