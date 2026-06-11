#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define pb push_back
#define endl '\n'
#define snd second
#define fst first
#define fastio cin.tie(NULL),cout.sync_with_stdio(true)

typedef long long int ll;
typedef unsigned long long int ull;
typedef vector <int> vi;
typedef pair <int, int> ii;

const int mod = 1e9 + 7;
const ll INF = (1LL<<50);
const double EPSILON = 0.001;
const int N = 200005;
int main(){
	fastio;
	string a,b;
	cin >> a >> b;
	int ans = 1;
	for(int i = 0; i < sz(a); i++){
		if(a[i] != b[i])ans = 0;
	}
	if(sz(b) > sz(a) + 1)ans = 0;
	cout << (ans?"Yes":"No") << '\n';
	return 0;
}
