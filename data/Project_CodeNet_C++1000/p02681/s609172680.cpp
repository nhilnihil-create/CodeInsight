#include <bits/stdc++.h>
using namespace std;

#define len(s) int(s.size())
#define res(x) cout<<((x)?"Yes\n":"No\n")
#define all(v) v.begin(),v.end()

typedef long long ll;
typedef long double ld;

ll mod = 1e9+7;

void solution() {
	string s, t;
	cin >> s >> t;

	bool ans = true;
	for(int i = 0; i < len(s); ++i) {
		if(s[i] != t[i]) {
			ans = false;
		}
	}

	res(ans);
	
}

int main(){
	
	int t = 1;
	//cin >> t;
	
	while(t--)
		solution();
	
	return 0;
}
