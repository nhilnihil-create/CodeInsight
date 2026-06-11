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
	int n = s.size();

	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		a[i] = s[i] - '0';
	}

	vector<ll> dp1(n + 1,0LL);//i桁目まででLより小さいことが確定したa,b
	vector<ll> dp2(n + 1,0LL);//i桁目まででLと一致しているa,b
	dp2[0] = 1;
	for(int i = 1; i < n + 1; i++) {
		if (a[i - 1] == 1){
			dp1[i] = (dp2[i - 1] + dp1[i - 1] * 3) % mod;
			dp2[i] = (dp2[i - 1] * 2) % mod;
		}
		else{
			dp1[i] = (dp1[i - 1] * 3) % mod;
			dp2[i] = dp2[i - 1];
		}
	}
	cout << (dp1[n] + dp2[n]) % mod << endl;
	return 0;
}