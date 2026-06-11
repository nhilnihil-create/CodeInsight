#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ii pair<int,int>
#define vi vector<int>
#define vll vector<ll>
#define vii vector<ii>

const int INF = 0x3f3f3f3f;
const ll  LINF = 0x3f3f3f3f3f3f3f3fLL;
const int maxn = 45+10;
const int mod = 1e9+7;

using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	int n,ans=0;
	string s;

	cin >> n >> s;

	set<int> r,w;

	for(int i=0;i<n;++i){
		if(s[i]=='R') r.insert(i);
		else w.insert(i);
	}

	ans = min(w.size(),r.size());

	int moves = 0;

	while(!r.empty() && !w.empty() && *(w.begin()) < *(r.rbegin()) ) {
		++moves;
		int x = *(w.begin()); w.erase(x); r.insert(x);
		x = *(r.rbegin()); r.erase(x); w.insert(x);
	}

	ans = min(ans,moves);

	cout << ans << endl;

    return 0;
}

