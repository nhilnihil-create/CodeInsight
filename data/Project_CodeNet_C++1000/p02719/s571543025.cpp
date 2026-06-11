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
typedef pair <ll,int> ii;
typedef pair <ii,int> iii;

const int mod = 1e9 + 7;
const int N = 100005;

/*
	se n>=k
	|(n-k)| = (n-k)
	=>||(n-k)| - k| = (n - 2*k) .... min = lower bound , upper bound de (n,k)

	else se n < k
	|(n-k)| = (k-n)
	=>||(n-k)| - k| = |-n| = n ... min = min(k-n, n)
*/

void solve(){
	ll n,k;
	cin >> n >> k;
	if(n >= k){
		cout << min(abs(n-k * (n/k)),abs(n-k * (n/k+1))) << endl;
	}else{
		cout << min(n, k-n) << endl;
	}
}

int main(){
	fastio;
	int t = 1;
	//cin >> t;
	while(t--)
		solve();
	return 0;
}
