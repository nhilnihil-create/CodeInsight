#include <bits/stdc++.h>
#define inc(l,i,r) for (int i=l;i<=r;i++)
#define dec(r,i,l) for (int i=r;i>=l;i--)
#define SIZE(V) ((int) V.size())
#define forE(p,u) for (edge *p=head[u];p;p=p->nxt)
#define forV(i,V) for (int i=0;i<SIZE(V);i++)
#define pb push_back
#define In inline
#define fi first
#define se second
#define mp make_pair
#define It iterator
#define ___ putchar(10);
#define cnt(x) __builtin_popcount(x)
#define show(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int N = 100100, P = 998244353;

int main() {
	//freopen("_in.txt","r",stdin);
	int x;
	scanf("%d",&x);
	for (int k=1;k<=360;k++) if (k*x % 360 == 0) {
		printf("%d\n",k);
		break;
	}
}