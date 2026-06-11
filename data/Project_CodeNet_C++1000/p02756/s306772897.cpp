#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;
using ll=long long;
using P=pair<int,int>;
#define rep(i,a,b) for(ll i=a;i<ll(b);i++)
#define repr(i,a,b) for(ll i=a;i>=ll(b);i--)
#define endl '\n'
#define ALL(x) x.begin(),x.end()
#define ALLR(x) x.rbegin(),x.rend()
#define INF 1e9
#define DEBUG(x) cout<<"debug: "<<x<<endl
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}

string s;
int q;
bool isReverse;
int main(){
	cin >> s >> q;
	rep(_, 0, q){
		int t; cin >> t;
		if(t-1){
			int f; char c; cin >> f >> c;
			if(isReverse){
				if(f-1) s = c + s;
				else s += c;
			}
			else{
				if(f-1) s += c;
				else s = c + s;
			}
		}
		else isReverse = !isReverse;
	}
	if(isReverse) s = string(ALLR(s));
	cout << s << endl;
    return 0;
}
