#include<bits/stdc++.h>
#define ff first
#define ss second
#define len(x) (int)(x.size())
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define MAXN 100010
#define MAXLOGN 20
#define comp(a, b) max((a), (b))
int st[MAXN][MAXLOGN];

void init(int* bg, int*en){
	int sz = int(en-bg);
	for(int i=0; i<sz; ++i) st[i][0] = bg[i];
	for(int j=1; 1 << j <= sz; ++j)
		for(int i=0; i + (1<<j) <= sz; ++i)
			st[i][j] = comp(st[i][j-1], st[i + (1<<(j-1))][j-1]);
}
int query(int l, int r){
	int k = (int) floor(log((double)r-l+1) / log(2.0));
	return comp(st[l][k], st[r-(1<<k)+1][k]);
}

int pos[MAXN];
int vs[MAXN];

int greaterLeft(int l, int r, int x){
	if(l>r) return -1;
	int y = query(l, r);
	if(y<=x) return -1;

	++r;
	while(r-l>1){
		int k = l + (r-l)/2;
		y = query(k, r-1);
		if(y>x) l = k;
		else r = k;
	}
	return vs[l];
}
int greaterRight(int l, int r, int x){
	if(l>r) return -1;
	int y = query(l, r);
	if(y<=x) return -1;

	--l;
	while(r-l>1){
		int k = l + (r-l)/2;
		y = query(l+1, k);
		if(y>x) r = k;
		else l = k;
	}
	return vs[r];
}
int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
		scanf("%d", &vs[i]), pos[vs[i]] = i;
	init(vs, vs+n);
	ll ans = 0;
	for(int x=1; x<=n; ++x){
		int y;
		ll res = 0;

		// Left
		y = greaterLeft(0, pos[x]-1, x);
		//cout << pos[x]-1 << endl;
		//cout << x << "*(";
		if(y>x){
			int xl = greaterLeft (0, pos[y]-1, x);
			int xr = greaterRight(pos[x]+1, n-1, x);
			ll r1, r2;
			if(xl==-1) r1 = pos[y]+1;
			else r1 = pos[y]-pos[xl];
			if(xr==-1) r2 = n-pos[x];
			else r2 = pos[xr]-pos[x];
			res += r1*r2*ll(x);
		//	cout << r1 << "*" << r2;
		}
		y = greaterRight(pos[x]+1, n-1, x);
		if(y>x){
			int xl = greaterLeft (0, pos[x]-1, x);
			int xr = greaterRight(pos[y]+1, n-1, x);
			ll r1, r2;
			if(xl==-1) r1 = pos[x]+1;
			else r1 = pos[x]-pos[xl];
			if(xr==-1) r2 = n-pos[y];
			else r2 = pos[xr]-pos[y];
			res += r1*r2*ll(x);
		//	cout << " + "<< r1 << "*" << r2;
		}
		//cout << ") " << endl;
		ans += res;
	}
	cout << ans << endl;
}
