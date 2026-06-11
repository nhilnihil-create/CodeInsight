#include<iostream>
#include<sstream>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<complex>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cassert>

#define rep(i,n) for(int i=0;i<(int)n;i++)
#define all(c) (c).begin(),(c).end()
#define mp make_pair
#define pb push_back
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define dbg(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<endl

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int inf = (int)1e9;
const double INF = 1e12, EPS = 1e-9;

int main(){
	string s;
	while(getline(cin, s), s != "."){
		vi v;
		bool ok = 1;
		rep(i, s.size()){
			if(s[i] == '(') v.pb(1);
			if(s[i] == ')'){
				if(!v.size() || v.back() != 1) ok = 0;
				else v.pop_back();
			}
			if(s[i] == '[') v.pb(2);
			if(s[i] == ']'){
				if(!v.size() || v.back() != 2) ok = 0;
				else v.pop_back();
			}
			if(!ok) break;
		}
		cout << (ok && !v.size() ? "yes" : "no") << endl;
	}
	return 0;
}