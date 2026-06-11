#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	ll n,k;cin>>n>>k;
	vector<ll> p(n + 1);
	vector<ll> c(n + 1);
	for(int i = 1; i <= n; i++) {
		cin>>p[i];
	}
	for(int i = 1; i <= n; i++) {
		cin>>c[i];
	}
	vector<ll> sum_c(n + 1,0LL);
	vector<ll> sum_cnt(n + 1,0LL);
	for(int i = 1; i <= n; i++) {
		ll index = i;
		ll sum = 0LL;
		ll cnt = 0LL;
		while(1){
			sum += c[p[index]];
			index = p[index];
			cnt++;
			if(index == i){
				break;
			}	
		}
		sum_c[i] = sum;
		sum_cnt[i] = cnt;
		// cout << cnt << endl;
	}

	// cout << amari << endl;
	ll res = -INF;
	for(ll i = 1; i <= n; i++) {
		ll point = 0LL;
		ll index = i;
		ll m = 1LL;
		if (k / sum_cnt[i] != 0){
			res = max(res,k / sum_cnt[i] * sum_c[i]);
		}
		if (sum_c[i] > 0LL){
			while(m <= sum_cnt[i]){
				if(m > k){break;}
				point+= c[p[index]];
				index = p[index];
				if((k - m) / sum_cnt[i] != 0LL || m != 0LL){
					res = max(res,point + (k - m) / sum_cnt[i] * sum_c[i]);
					// cout << res << endl;
				}
				m++;	
			}
		}
		else{
			while(m <= min(k,sum_cnt[i])){
				point+= c[p[index]];
				index = p[index];
				res = max(res,point);
				m++;	
			}
		}
	}
	cout << res << endl;
	return 0;
}