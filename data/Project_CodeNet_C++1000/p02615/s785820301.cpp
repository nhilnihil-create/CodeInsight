#include <cstdio>
#include <queue>
#include <algorithm>
#define maxn 200005
using namespace std;

int a[maxn], n;

struct Position
{
	int lf, rf, comfort;
	inline Position(int l, int r)
	{
		lf = l, rf = r;
		comfort = min(l, r);
	}
	inline bool operator<(const Position& p) const
	{
		return comfort < p.comfort;
	}
};

priority_queue<Position> q;

inline bool cmp(int x, int y) {return x > y;}

int main(int argc, char** argv)
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", a + i);
	sort(a, a + n, cmp);
	q.push(Position(a[0], a[1]));
	long long res = a[0];
	for(int i=2; i<n; i++)
	{
		Position p = q.top();
		if(q.size() > 1) q.pop();
		res += p.comfort;
		q.push(Position(a[i], p.lf));
		q.push(Position(a[i], p.rf));
	}
	printf("%lld\n", res);
	return 0;
}