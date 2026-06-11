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

void testcase(){
	int n;
	string s;
	cin >> n >> s;
	int ans = 0;
	for(int i{0};i <= n-3;i++){
		if(s.substr(i,3) == "ABC")ans++;
	}
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
