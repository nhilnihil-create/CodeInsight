// E - Dist Max
#include <bits/stdc++.h>
using namespace std;

int main(){
	int N; cin>>N;
	int64_t p[N], m[N];
	for(int i=0; i<N; ++i){
		int x, y; cin>>x>>y;
		p[i] = x + y;
		m[i] = x - y;
	}
	sort(p, p + N);
	sort(m, m + N);
	cout<< max(p[N-1] - p[0], m[N-1] - m[0]) <<endl;
}
