#include <bits/stdc++.h>

using namespace std;

#define fo(i,n) for(int i=0;i<n;i++)
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define lli long long int
#define all(c) c.begin(),c.end()
#define lower(c) tolower(c)
#define upper(c) toupper(c)
#define MAX(c) *max_element(c.begin(),c.end())
#define MIN(c) *min_element(c.begin(),c.end())
#define len(c) c.size()
const int MOD = 1000000007;
const int MX = 2e5 + 5;
const int INF = 1e9 + 10;
const lli LINF = 1e18;

void solve() {
	lli x,k,d;
	cin >> x >> k >> d;
	x=abs(x);
	lli s=min(k,x/d);
	k-=s;
	x-=s*d;
	if(k&1)cout << d-x << endl;
	else cout << x << endl;

}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	solve();
    return 0;
}

