#include <bits/stdc++.h>
#define INF 1000000007
#define rep(i, N) for(ll i = 0; i < N; i++)
#define rep2(i, j, k) for(ll i = j; i < k; i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define print(x) cout << x << "\n"
#define print2(x, y) cout << x << " " << y << "\n"
#define printv(vec) rep(i, vec.size()) cout << vec[i] << " "; print("");
#define ALL(v) v.begin(), v.end()
#define SUM(v) accumulate(ALL(v), 0)
#define MAX(v) *max_element(ALL(v))
#define MIN(v) *min_element(ALL(v))
#define SORT(v) sort(ALL(v))
#define REV(v) reverse(ALL(v))
typedef long long ll;
using namespace std;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using vs = vector<string>;

void Main(){

	ll X, Y, A, B, C;
	cin >> X >> Y >> A >> B >> C;
	vl p(A);
	vl q(B);
	vl r(C);
	rep(i, A) cin >> p[i];
	rep(i, B) cin >> q[i];
	rep(i, C) cin >> r[i];
	
	SORT(p); SORT(q); SORT(r);
	REV(r);
	ll ans = 0;
	ll ind1 = A - X;
	ll ind2 = B - Y;
	rep2(i, ind1, A) ans += p[i];
	rep2(i, ind2, B) ans += q[i];
	ll ind3 = 0;
	ll ma, mb;
	rep(i, C){
		
		if(ind1 == A && ind2 == B) break;
		if(ind1 == A) ma = INF;
		else ma = p[ind1];
		if(ind2 == B) mb = INF;
		else mb = q[ind2];
		
		if(ma >= mb){
			if(mb < r[ind3]){
				ans -= mb;
				ans += r[ind3];
				ind2++;
				ind3++;
			}
		}
		else{
			if(ma < r[ind3]){
				ans -= ma;
				ans += r[ind3];
				ind1++;
				ind3++;
			}
		}
	}
	
	print(ans);
	
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	Main();
    
	return 0;
	
}



