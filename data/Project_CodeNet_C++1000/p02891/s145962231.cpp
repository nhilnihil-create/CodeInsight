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

int main(){
	string s;cin>>s;
	ll k;cin>>k;
	ll ans = 0;
	ll tmp = 1;
	bool flag = true;
	for(int i = 0; i < s.size() - 1; i++) {
		if (s[i] == s[i + 1]){
			tmp ++;
		}
		else{
			flag = false;
			ans += (tmp / 2);
			tmp = 1;
		}
	}

	ans += (tmp / 2);

	if (flag){
		cout << k * s.size() / 2 << endl;
		return 0;
	}

	if (s[0] != s[s.size() - 1]){
		cout << k * ans << endl;
		return 0;
	}

	ll a = 1;
	ll b = 1;
	for(int i = 1; i < s.size(); i++) {
		if(s[i] == s[0]){
			a ++;
		}
		else{
			break;
		}
	}
	for(int i = 1; i < s.size(); i++) {
		if(s[s.size() - i - 1] == s[s.size() - 1]){
			b++;
		}
		else{
			break;
		}
	}

	cout << ans * k + (k - 1) * ((a + b) / 2 - (a / 2) - (b / 2)) << endl;

	return 0;
}