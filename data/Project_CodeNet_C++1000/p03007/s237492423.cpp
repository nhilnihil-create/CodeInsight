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
const ll INF=1<<30;

int main(){
	ll n;cin>>n;
	vector<ll> po;
	vector<ll> ne;
	for(int i = 0; i < n; i++) {
		ll x;cin>>x;
		if (x >= 0){
			po.pb(x);
		}
		else{
			ne.pb(x);
		}
	}
	sort(ALL(po),greater<ll>());
	sort(ALL(ne));
	if (ne.size() == 0){
		ne.pb(po.back());
		po.pop_back();
	}
	if (po.size() == 0){
		po.pb(ne.back());
		ne.pop_back();
	}
	vector<P> v;
	while(1){
		if (po.size() == 1 && ne.size() == 1){
			v.pb(mp(po[0],ne[0]));
			cout << po[0] - ne[0] << endl;
			break;
		}
		else if (po.size() > 1){
			ll pos = po.back();
			ll neg = ne.back();
			po.pop_back();
			ne.pop_back();
			ne.pb(neg - pos);
			v.pb(mp(neg,pos));
		}
		else if (ne.size() > 1){
			ll pos = po.back();
			ll neg = ne.back();
			po.pop_back();
			ne.pop_back();
			po.pb(pos - neg);
			v.pb(mp(pos,neg));
		}
	}
	for(int i = 0; i < v.size(); i++) {
		cout << v[i].fs << " "<< v[i].sc << endl;
	}
	
	return 0;
}