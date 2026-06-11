#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define Rep(n) for (ll _ = 0; _ < (ll)(n); _++)
#define fs first
#define sc second

template<class S>S sum(vector<S>&a){return accumulate(all(a),S());}
template<class S>S max(vector<S>&a){return *max_element(all(a));}
template<class S>S min(vector<S>&a){return *min_element(all(a));}
ll max(int a,ll b){return max((ll)a,b);} ll max(ll a,int b){return max(a,(ll)b);}
ll min(int a,ll b){return min((ll)a,b);} ll min(ll a,int b){return min(a,(ll)b);}
template <class S> void print(vector<S> &v){for(ll i=0; i<(ll)v.size(); i++){cerr << v[i] << ' ';}cerr << endl;}
template <class S> void print(vector<vector<S>> &v) {for (ll i = 0; i < (ll)v.size(); i++) {for (ll j = 0; j < (ll)v[i].size(); j++) {cerr << v[i][j] << ' ';}cerr << endl;}}

int main(){
	string s; cin >> s;
	int n = s.size();
	vector<int> ans(n,0);
	int even = 0;
	int odd = 0;
	bool iseven = true;
	rep(i,n){
		if(s[i] == 'R'){
			if(iseven) even++;
			else odd++;
			iseven = !iseven;
		}else{
			if(iseven){
				ans[i] += even;
				ans[i-1] += odd;
			}else{
				ans[i] += odd;
				ans[i-1] += even;
			}
			even = 0;
			odd = 0;
			iseven = true;
		}
	}
	for(int i=n-1; i>=0; i--){
		if(s[i] == 'L'){
			if(iseven) even++;
			else odd++;
			iseven = !iseven;
		}else{
			if(iseven){
				ans[i] += even;
				ans[i+1] += odd;
			}else{
				ans[i] += odd;
				ans[i+1] += even;
			}
			even = 0;
			odd = 0;
			iseven = true;
		}
	}
	rep(i,n) cout << ans[i] << ' ';
}

