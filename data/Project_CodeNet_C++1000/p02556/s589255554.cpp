// E - Dist Max
#include <bits/stdc++.h>
using namespace std;

int main(){
	int64_t N, x, y, p[2], m[2];
	cin>>N>>x>>y;
	p[0] = p[1] = x + y;
	m[0] = m[1] = x - y;
	while(--N){
		cin>>x>>y;
		tie(p[0], p[1]) = minmax({p[0], p[1], x + y});
		tie(m[0], m[1]) = minmax({m[0], m[1], x - y});
	}
	cout<< max(p[1] - p[0], m[1] - m[0]) <<endl;
}
