#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





using ll = long long;

const ll mod = 1e9+7;
const int maxn = 1e6 + 5;




int make(int mask, vector<string> g) {
    int n = g.size();
    int m = g[0].size();
    for (int bit=0; bit<n; bit++) {
	if (mask>>bit&1) {
	    for (int j=0; j<m; j++) {
		g[bit][j]='x';
	    }
	}
    }
    for (int bit=n; bit<n+m; bit++) {
	if (mask>>bit&1) {
	    for (int i=0; i<n; i++) {
		g[i][bit-n]='x';
	    }
	}
    }

    int res = 0;
    for (int i=0; i<n; i++) {
	for (int j=0; j<m; j++) {
	    res += (g[i][j]=='#');
	}
    }
    return res;
}

int n,m,k;
vector<string> g;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    cin>>n>>m>>k;
    g.resize(n);
    for (int i=0; i<n; i++) {
	cin>>g[i];
    }

    int ans = 0;

    for (int mask=0; mask<(1<<(n+m)); mask++) {
	int cnt = make(mask, g);
	ans += (cnt==k);
    }

    cout<<ans<<endl;    
    
    return 0;
}
