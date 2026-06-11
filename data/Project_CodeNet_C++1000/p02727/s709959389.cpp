#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

//#include "atcoder/all"
//using namespace atcoder;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int x, y, a, b, c;
	cin >> x >> y >> a >> b >> c;
	priority_queue<ll> p, q, r;
	rep(i,a){
		ll d;
		cin >> d;
		p.push(d);
	}
	rep(i,b){
		ll d;
		cin >> d;
		q.push(d);
	}
	rep(i,c){
		ll d;
		cin >> d;
		r.push(d);
	}
	r.push(-1);
	int red = 0, green = 0;
	ll ans = 0;
	rep(i,x+y){
		ll A = p.top();
		ll B = q.top();
		ll C = r.top();
		if(B <= A && C <= A){
			p.pop();
			ans += A;
			++red;
			if(red == x){
				while(!p.empty()) p.pop();
				p.push(-1);
			}
		}
		else if(A <= B && C <= B){
			q.pop();
			ans += B;
			++green;
			if(green == y){
				while(!q.empty()) q.pop();
				q.push(-1);
			}
		}
		else{
			r.pop();
			ans += C;
		}
	}
	cout << ans << endl;
	return 0;
}