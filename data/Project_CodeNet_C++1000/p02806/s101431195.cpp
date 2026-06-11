/* _________________________________________________________________________________________________
  |                                                                                                 |
  |                             Author      : Aditya Ahuja                                          |
  |                             Date        : Mon, 20th Jan 2020                                    |
  |_________________________________________________________________________________________________|
*/
 
#include<bits/stdc++.h>
using namespace std;

#define int long long

#define pb          push_back
#define F           first
#define S           second
#define endl        "\n"
#define rep(i,a,b)  for(int i = a; i < (int)b; i++)
#define req(i,a,b)  for(int i = (int)b - 1; i >= a; i--)
#define all(a)      (a).begin(),(a).end()
#define ret(x)      {cout << x << endl; return;}
#define sz(x)       (int)x.size()
#define type(x)     typeid(x).name()

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<vector<int>> vii;

int gcd(int a, int b) {return b?gcd(b,a%b):a;}

#ifdef LOCAL
	#define wa(x)       cerr << (#x) << " --- " << (x) << endl
	#define pvi(v)      {for(auto it:v) cerr << it << " "; cerr << endl;}
	#define line1	    cerr << "---------------------------" << endl;
#else
	#define wa //
	#define line1 //
	#define pvi //
	#define printf //
#endif

void solve();
signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cout << fixed << setprecision(10);

	int t=1; 
	// cin>>t;
	while(t--) solve();
	return 0;
}

//___________________________________________________________________________________________________

void solve() {

	int n;
	cin >> n;

	vector<string> s;
	vi t;

	rep(i,0,n){
		string ss; 
		int tt;
		cin >> ss >> tt;
		s.pb(ss);
		t.pb(tt);
	}

	string a;
	cin >> a;

	int tot = 0;
	int sum = accumulate(all(t), 0ll);

	rep(i,0,n){
		tot += t[i];
		if(s[i] == a) break;
	}

	ret(sum-tot);
}
