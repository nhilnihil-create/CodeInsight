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
#define max(c) *max_element(c.begin(),c.end())
#define min(c) *min_element(c.begin(),c.end())
#define len(c) c.size()
const int MOD = 1000000007;
const int MX = 2e5 + 5;
const int INF = 1e9 + 10;
const lli LINF = 1e18;

void solve() {
	string s,t;
	cin >> s >> t;
	long long c=0;
	//sort(all(s));
	//sort(all(t));
	fo(i,len(s))
		if(s[i]!=t[i])c++;
	cout << c;

}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	solve();


    return 0;
}




