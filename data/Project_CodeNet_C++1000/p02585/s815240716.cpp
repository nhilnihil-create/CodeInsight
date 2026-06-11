#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

const ll INF = 1LL<<60;

int main(){
	ll n,k;
	cin >> n >> k;
	vector<ll> p(n);
	vector<ll> c(n);
	rep(i,n) cin >> p[i], p[i]--;
	rep(i,n) cin >> c[i];
	//まずサイクル成分に分ける
	vector<bool> seen(n);
	ll ans = -INF;
	rep(i,n){
		vector<ll> score; //サイクル成分のスコアを格納
		if(!seen[i]){
			int idx = i;
			while(!seen[idx]){
				seen[idx] = true;
				score.push_back(c[idx]);
				idx = p[idx];
			}
			ll sum = 0;
			for(auto p: score) sum += p;
			//一つのサイクル成分について, 始点と終点を前通り試す。
			ll L = score.size();
			for (int a = 0; a < L; ++a) {
				ll ab_length = 0;
				ll ab_score = 0;
				for (int b = a + 1; b <= L + a ;++b) {
					int tempb = b % L;
					ab_length++;
					ab_score += score[tempb];
					if(ab_length > k) continue;
					ll ab_score_max = ab_score + max(sum, ll(0)) * ((k - ab_length) / L);
					ans = max(ans, ab_score_max);
				}
			}
		}
	}
	cout << ans << endl;
    return 0;
}

