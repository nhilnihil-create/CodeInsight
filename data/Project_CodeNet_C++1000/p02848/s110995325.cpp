#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define INF 1000000007
#define mod 1005
#define ll long long int
const double mx = 2e6 + 5 ;

void solve()
{
	vector<char> vect;
	for(char ch ='A'; ch<='Z'; ch++)
	{
		vect.push_back(ch);
	}
	int n;
	cin>>n;
	string s;
	cin>>s;
	for(int i=0; i<s.length(); i++)
	{
		int val = ((s[i]-'A')+n)%26;
		cout<<vect[val];
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t = 1;
//	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}