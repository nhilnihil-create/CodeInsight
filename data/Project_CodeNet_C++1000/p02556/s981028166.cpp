// E - Dist Max
#include <bits/stdc++.h>
using namespace std;

int main(){
	int N; cin>>N;
	vector<int64_t> p, m;
	while(N--){
		int x, y; cin>>x>>y;
		p.push_back(x + y);
		m.push_back(x - y);
	}
	sort(p.begin(), p.end());
	sort(m.begin(), m.end());
	cout<< max(p.back() - p[0], m.back() - m[0]) <<endl;
}
