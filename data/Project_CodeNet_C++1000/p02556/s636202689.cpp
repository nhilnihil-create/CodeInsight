// E - Dist Max
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main(){
	int N; cin>>N;
	ll p_mn, m_mn = p_mn = 1e9 * 2;
	ll p_mx, m_mx = p_mx = -p_mn;
	while(N--){
		ll x, y; cin>>x>>y;
		ll p = x + y, m = x - y;
		p_mx = max(p_mx, p);
		p_mn = min(p_mn, p);
		m_mx = max(m_mx, m);
		m_mn = min(m_mn, m);
	}
	cout<< max(p_mx - p_mn, m_mx - m_mn) <<endl;
}
