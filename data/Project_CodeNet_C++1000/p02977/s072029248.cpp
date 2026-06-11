#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <queue>
#include <set>
#include <math.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P> Q;
const ll mod = 1000000007;
const ll INF = 1000000000000000;
vector<P> vec[200010], peo[200010];
ll bit[100010], num;
ll par[100010], sz[100010];
ll n;

struct edge { ll to, cost; };
ll V;
vector<edge> G[300010];
ll d[300010];

ll root(int x) { // �f�[�^x��������؂̍����ċA�œ���Froot(x) = {x�̖؂̍�}
	if (par[x] == x) return x;
	return par[x] = root(par[x]);
}

void unite(int x, int y) { // x��y�̖؂𕹍�
	int rx = root(x); //x�̍���rx
	int ry = root(y); //y�̍���ry
	if (rx == ry) return; //x��y�̍�������(=�����؂ɂ���)���͂��̂܂�
	par[rx] = ry; //x��y�̍��������łȂ�(=�����؂ɂȂ�)���Fx�̍�rx��y�̍�ry�ɂ���
}

bool same(int x, int y) { // 2�̃f�[�^x, y��������؂������Ȃ�true��Ԃ�
	int rx = root(x);
	int ry = root(y);
	return rx == ry;
}

void dijkstra(ll s)
{
	priority_queue<P, vector<P>, greater<P>> que;
	for (int i = 0; i <= 300010; i++)
	{
		d[i] = INF;
	}
	d[s] = 0;
	que.push(P(0, s));

	while (!que.empty())
	{
		P p = que.top(); que.pop();
		ll v = p.second;
		if (d[v] < p.first) continue;
		for (ll i = 0; i < G[v].size(); i++)
		{
			edge e = G[v][i];
			if (d[e.to] > d[v] + e.cost)
			{
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to], e.to));
			}
		}
	}
}

ll sum(ll i)
{
	ll s = 0;
	while (i > 0)
	{
		s += bit[i];
		i -= i & -i;
	}
	return s;
}

void add(ll i, ll x)
{
	while (i <= num)
	{
		bit[i] += x;
		i += i & -i;
	}
}

ll po(ll x, ll y)
{
	if (y == 0) return 1;
	if (y % 2)
	{
		return po(x, y - 1) * x % mod;
	}
	else
	{
		ll yyy = po(x, y / 2);
		return yyy * yyy % mod;
	}
}

ll pow_mod(ll x, ll y)
{
	ll res = 1;
	while (y > 0)
	{
		if (y % 2 == 1)
		{
			(res *= x) %= mod;
		}
		(x *= x) %= mod;
		y /= 2;
	}
	return res;
}

ll div(ll x)
{
	return po(x, mod - 2);
}

int main(void)
{
	cin >> n;
	if (n == 3)
	{
		cout << "Yes" << endl;
		for (int i = 1; i < 6; i++)
		{
			cout << i << ' ' << i + 1 << endl;
		}
		return 0;
	}
	ll two_pow = 1;
	while (two_pow < n)
	{
		two_pow *= 2;
	}
	if (two_pow == n)
	{
		cout << "No" << endl;
	}
	else
	{
		cout << "Yes" << endl;
		two_pow /= 2;
		for (int i = 1; i < two_pow - 1; i++)
		{
			cout << i << ' ' << i + 1 << endl;
		}
		cout << two_pow - 1 << ' ' << 1 + n << endl;
		for (int i = 1; i < two_pow - 1; i++)
		{
			cout << i + n << ' ' << i + n + 1 << endl;
		}
		for (int i = two_pow + 1; i <= n; i++)
		{
			cout << i - two_pow << ' ' << i << endl;
		}
		for (int i = two_pow + 2; i <= n; i++)
		{
			cout << i - 1 << ' ' << i + n << endl;
		}
		cout << 1 << ' ' << two_pow << endl;
		cout << two_pow << ' ' << n + two_pow + 1 << endl;
		cout << two_pow + 1 << ' ' << n + two_pow << endl;
	}
	int www;
	cin >> www;
}
