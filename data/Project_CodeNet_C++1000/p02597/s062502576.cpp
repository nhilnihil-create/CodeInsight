#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define mt make_tuple
#define MOD 1000000007
#define fo(i,a,b) for(i=a;i<b;i++)
#define foe(i,a,b) for(i=a;i<=b;i++)
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define vl vector <long long int>
#define pii pair <int,int>
#define pll pair <long long int, long long int>
#define vpii vector< pair<int,int> >
#define vpll vector < pair <long long int,long long int> >
#define boost ios::sync_with_stdio(false); cin.tie(0)
using namespace std;
const int inf = 1e9 + 5;
const ll inf64 = 1e18 + 5;

int main()
{
	boost;
	int n, i;
	cin >> n;
	string s;
	cin >> s;
	
	int r = 0, w = 0;
	for(char c : s) {
		if(c == 'R') r++;
		else w++;
	}
	
	int totr = 0, totw = 0;
	fo(i, 0, r) {
		if(s[i] == 'R')
		totr++;
	}
	for(i = n - 1; i >= n - w; i--) {
		if(s[i] == 'W')
		totw++;
	}
	cout << min(r - totr, w - totw);
}
