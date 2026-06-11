//Har Har Mahadev
using namespace std;
#include <bits/stdc++.h>
#define booga cout << "booga" << endl
#define ll long long int
#define pb push_back
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " -> " << a << endl;
	err(++it, args...);
}
ll lcm(ll a, ll b){
	return a*b / __gcd(a,b);
}
int solve(ll x){
	int ans = 0;
	while(x % 2 == 0){
		ans++;
		x /= 2;
	}
	return ans;
}
void testcase(){
	unordered_set<int> s;
	ll n,m,a[100005],l = 1;
	cin >> n >> m;
	for(int i{0};i < n;i++){
		cin >> a[i];
		a[i] /= 2;
		l = lcm(l,a[i]);
		s.insert(solve(a[i]));
	}
	if(s.size() > 1){
		cout << 0;
	}
	else{
		cout << (1 + m/l) / 2;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	while(t--){
		testcase();
	}
	return 0;
}
