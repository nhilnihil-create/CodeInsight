#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;
 
#define pb push_back
#define f first
#define s second
#define fr(i, n) for(ll i = 0; i < n; i++)
#define frr(i, n) for(ll i = 1; i<= n; i++)
#define MOD 1000000007
const ll MAX = 112345;
ll x, y, a, b, c;
ll q[MAX], r[MAX], p[MAX];
vector<ll> aux;
ll ans;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> x >> y >> a >> b >> c;
	fr(i, a){
		cin >> p[i];
		p[i] = -p[i];
	}
	fr(i, b){
		cin >> q[i];
		q[i] = -q[i];
	}
	fr(i, c){
		cin >> r[i];
		/*r[i] = -r[i];*/
	}
	sort(p, p+a);
	sort(q, q+b);
	sort(r, r+c);
	fr(i, x){
		aux.push_back(-p[i]);
	}
	fr(i, y){
		aux.push_back(-q[i]);
	}

	sort(aux.begin(), aux.end());

	ll i, j;
	j = c-1;
	for(i = 0; i < aux.size(); i++){
		if(j >= 0 && r[j] > aux[i]){
			ans += r[j];
			j--;
		}
		else{
			ans += aux[i];
		}
	}
	cout << ans << endl;

}
