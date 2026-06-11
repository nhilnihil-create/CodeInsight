#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)

typedef long long ll;
typedef pair<int,int> P;

int main(){
	ll N,D,A;
	cin >> N >> D >> A;
	vector<P> E(N);
	rep(i,N){ int x,h; cin >> x >> h; E[i]=P(x,h); }
	sort(E.begin(),E.end());

	ll cnt = 0;
	int num = 0;
	ll range = D*2;
	ll dam = 0;
	queue<pair<ll,ll>> q;
	while(num < N){
		int loc = E[num].first;
		int hp = E[num].second;
		
		while(q.size() &&  q.front().first < loc){
			dam -= q.front().second;
			q.pop();
		}
		hp -= dam;
		if(hp>0){
			ll c = (hp+A-1)/A;
			cnt += c;
			ll damage = c * A;
			dam += damage;
			q.emplace(loc+range, damage);
		}
		num++;
	}

	cout << cnt << endl;
	return 0;
}
