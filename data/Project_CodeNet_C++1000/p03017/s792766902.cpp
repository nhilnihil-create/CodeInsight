#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) do{}while(0)
#endif





ll n, a, b, aa, bb;
string s;

vector<int> va, vb;

bool test(){
	// 到達可能な位置を調べる
	for ( int i = aa-1; i >= a; i-- ){
		if ( s[i] != '#' && ( va[i+1] | va[i+2] ) )
			va[i] = 2;
	}
	for ( int i = bb-1; i >= b; i-- ){
		if ( s[i] != '#' && ( vb[i+1] | vb[i+2] ) )
			vb[i] = 2;
	}
	
	//cout << s << endl;
	//for ( auto it : va )
	//	cout << it;
	//cout << "  " << endl;
	//for ( auto it : vb )
	//	cout << it;
	//cout << "  " << endl;
	
	if ( !va[a] || !vb[b] )
		return false;
	
	if ( aa > bb ){
		// 追い越し可能か?
		for ( int i = b; i <= bb; i++ ){
			if ( vb[i] && va[i-1] && va[i+1] ){
				return true;
			}
		}
		return false;
	}
	
	return true;
}

int main(){
	cin >> n >> a >> b >> aa >> bb;
	cin >> s;
	
	a--;
	b--;
	aa--;
	bb--;
	
	va.resize(n+2);
	vb.resize(n+2);
	va[aa] = 1;
	vb[bb] = 1;
	
	
	if ( test() ){
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	
	
	return 0;
}


