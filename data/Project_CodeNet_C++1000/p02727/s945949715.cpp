#include <bits/stdc++.h>
using namespace std;

int main() {
	long long		a,b,c,i,j,x,y,ans = 0;
	
	cin >> x >> y >> a >> b >> c;
	vector<int>	p(a),q(b),r(c),aa(x+y+c);
	for(i=0;i<a;i++) cin >> p[i];
	for(i=0;i<b;i++) cin >> q[i];
	for(i=0;i<c;i++) cin >> r[i];

	sort(p.begin(),p.end());
	reverse(p.begin(),p.end());
	sort(q.begin(),q.end());
	reverse(q.begin(),q.end());

	j = 0;
	for(i=0;i<x;i++) aa[j++] = p[i];
	for(i=0;i<y;i++) aa[j++] = q[i];
	for(i=0;i<c;i++) aa[j++] = r[i];

	sort(aa.begin(),aa.end());
	reverse(aa.begin(),aa.end());
	for(i=0;i<x+y;i++) ans += aa[i];

	cout << ans << endl;

}
