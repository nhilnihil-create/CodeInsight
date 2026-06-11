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

int n;
string s;
int main(){
	cin >> n >> s;
	vector<ll> a(3, 0);
	rep(i ,0, n) a[s[i]%3]++;
	
	ll U = a[0] * a[1] * a[2];
	ll A = 0;
	rep(j, 0, n) rep(i, 0, j){
		int k = 2*j - i;
		if(k >= n) continue;
		if(s[i] == s[j] || s[i] == s[k] || s[k] == s[j]) continue;
		A++;
	}
	
	cout <<	U-A << endl;
    return 0;
}
