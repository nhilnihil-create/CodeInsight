#include <iostream>
using namespace std;

const int N = 2e5+10;
int p[N], s[N];

int find(int x){
	return x == p[x] ? x : p[x] = find(p[x]);
}

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	int u, v;
	for(int i = 1; i <= n; i++){
		p[i] = i;
		s[i] = 1;
	}
	int res = 0;
	for(int i = 0; i < m; i++){
		scanf("%d%d", &u, &v);
		int ur = find(u);
		int vr = find(v);
		if(ur != vr){
			if(ur < vr) swap(ur, vr);
			s[vr] += s[ur];
			p[ur] = vr;
			res = max(res, s[vr]);
		}
	}
	cout << max(res, 1) << endl;
}
