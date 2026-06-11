#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define debug(x) cerr << #x << " " << x << '\n'
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pli = pair<ll,int>;
const int INF = 0x3f3f3f3f, N = 2e5 + 5;
const ll LINF = 1e18 + 5;

int main()
{
 	ios::sync_with_stdio(false);
 	cin.tie(0);
 	int n;
 	cin >> n;
 	vector <string> s(n);
 	vector <int> t(n);
 	for(int i=0; i<n; i++)
 	{
 		cin >> s[i] >> t[i];
 	}
 	string x;
 	cin >> x;
 	int sum = 0;
 	for(int i=0; i<n; i++)
 	{
 		if(s[i]==x)
 		{
 			for(int j=i+1; j<n; j++)
 				sum += t[j];
 			break;
 		}
 	}
 	cout << sum;
	return 0;
}
