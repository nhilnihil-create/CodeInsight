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

const int MAX = 1e6 + 5;
int smf[MAX], cnt[MAX];
void sieve()
{
	for(int i = 2; i < MAX; i++) {
		if(!smf[i]) {
			smf[i] = i;
			for(int j = 2 * i; j < MAX; j += i) {
				if(!smf[j]) 
				smf[j] = i;
			}
		}
	}
}
int main()
{
	boost;
	sieve();
	int n, i;
	cin >> n;
	
	int arr[n];
	fo(i, 0, n)
	cin >> arr[i];
	
	int g = 0;
	for(int x : arr)
	g = __gcd(g, x);
	
	for(int x : arr) {
		while(x > 1) {
			int y = smf[x];
			cnt[y]++;
			while(x % y == 0) x /= y;
		}
	}
	
	bool ok = 1;
	for(i = 2; i < MAX; i++)
	ok &= (cnt[i] < 2);
	
	if(ok) cout << "pairwise coprime";
	else if(g == 1) cout << "setwise coprime";
	else cout << "not coprime";
}
