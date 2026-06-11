#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <math.h>
#include <map>
#include <functional>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <typeinfo>
#define PI 3.14159265359
#define INF 99999999;
#define rep(i, n) for(int i=0; i<n; i++)
#define REP(n) rep(i, n)
#define EPS 1e-10
typedef long long ll;
using namespace std;
typedef pair<int, int> P;

double distanceAB(double xa, double ya, double xb, double yb);
void trace(int A[], int N);

/*
class Target
{
public:
	vector <string> draw(int n)
	{

	}
};
*/


#define MAX 100005
#define NIL -1

struct Node
{
	int p, l, r;
};

Node T[MAX];
int n, D[MAX];

void print(int u)
{
	int i, c;
	
	cout << "node " << u << ": ";
	cout << "parent = " << T[u].p << ", ";
	cout << "depth = " << D[u] << ", ";
	
	if (T[u].p == NIL) cout << "root, ";
	else if (T[u].l == NIL) cout << "leaf, ";
	else cout << "internal node, ";
	
	cout << "[";
	
	for (i=0, c=T[u].l; c!=NIL; i++, c=T[c].r)
	{
		if (i) cout << ", ";
		cout << c;
	}
	
	cout << "]" << endl;
}

int rec(int u, int p)
{
	D[u] = p;
	if (T[u].r != NIL) rec(T[u].r, p);
	if (T[u].l != NIL) rec(T[u].l, p + 1);
}


int main()
{
	int i, j, d, v, c, l, r;
	
	cin >> n;
	REP(n) T[i].p = T[i].l = T[i].r = NIL;
	
	rep(i, n)
	{
		cin >> v >> d;
		rep(j, d)
		{
			cin >> c;
			if (j == 0) T[v].l = c;
			else T[l].r = c;
			l = c;
			T[c].p = v;
		}
	}
	
	REP(n) if (T[i].p == NIL) r = i;
	
	rec(r, 0);
	
	REP(n) print(i);
	
	return 0;
}


void trace(int A[], int N)
{
	REP(N)
	{
		if (i > 0) cout << " ";
		cout << A[i];
	}
	cout << endl;
}


double distanceAB(double xa, double ya, double xb, double yb)
{
	return sqrt((xb-xa)*(xb-xa) + (yb-ya)*(yb-ya));
}