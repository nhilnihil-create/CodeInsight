#include <bits/stdc++.h>
using namespace std;
#define __ <<" "<<
#define ___ <<" "
#define bash push_back
#define ALL(x) x.begin(),x.end()
#define int long long
struct IoSetup {
	IoSetup() {
		cin.tie(0);
		ios::sync_with_stdio(false);
		cout << fixed << setprecision(10);
		cerr << fixed << setprecision(10);
	}
}IoSetup;
typedef long long ll;
typedef pair < int , int >  pii;
static const signed int INF = 0x3f3f3f3f;
static const signed long long LINF = 0x3f3f3f3f3f3f3f3fLL;
static const signed int SMOD = 1000000007;
static const signed int NMOD = 998244353;
static const signed int dx[]={1,0,-1,0,1,1,-1,-1};
static const signed int dy[]={0,-1,0,1,-1,1,-1,1};

inline bool inside(int x,int y,int w,int h){return (x>=0 && y>=0 && x<w && y<h);}
template<class T>bool chmax(T &a, const T&b){if(a<b)return(a=b,1);return 0;}
template<class T>bool chmin(T &a, const T&b){if(b<a)return(a=b,1);return 0;}



signed main() {
   
   string s;

	cin >> s;
	cout << s[0] << s[1] << s[2] << endl;

  return 0;
}
