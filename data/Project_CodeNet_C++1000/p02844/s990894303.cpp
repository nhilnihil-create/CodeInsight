#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





using ll = long long;

const ll mod = 1e9+7;
const int maxn = 1e6 + 5;



int n;
string s;

map<char, vector<int>> mp;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    cin>>n>>s;
    for (int i=0; i<n; i++) {
	mp[s[i]].push_back(i);
    }

    int ans = 0;

    for (int pin=0; pin<=999; pin++) {
	string cur = to_string(pin);
	while ((int)cur.length() < 3) {
	    cur = "0" + cur;
	}

	bool ok = true;
	for (char c: cur) {
	    if (mp[c].empty()) ok = false;
	}
	if (!ok) continue;

	ok = false;
	for (int i: mp[cur[1]]) {
	    if (*mp[cur[0]].begin() < i && *mp[cur[2]].rbegin() > i) {
		ok = true;
		break;
	    }
	}

	ans += ok;
    }


    cout<<ans<<endl;    
    return 0;
}
