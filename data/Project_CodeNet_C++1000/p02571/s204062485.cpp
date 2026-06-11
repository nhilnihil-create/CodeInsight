//Har Har Mahadev
using namespace std;
#include <bits/stdc++.h>
#define booga cout << "booga" << endl
#define ll long long int
#define pb push_back
#define mp make_pair
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " -> " << a << endl;
	err(++it, args...);
}
int solve(string a, string b){
	int n = a.size(),ans = 0;
	for(int i{0};i < n;i++)ans += a[i] != b[i];
	return ans;
}
void testcase(){
	string s,t;
	cin >> s >> t;
	int n = s.size(),m = t.size(),ans = 1e9;
	for(int i{0};i + m <= n;i++)ans = min(ans,solve(t,s.substr(i,m)));
	cout << ans;
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
