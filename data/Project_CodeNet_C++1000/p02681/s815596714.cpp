#include <iostream>
#include <string>
using ll=long long;
#define rep(i,a,b) for(ll i=a;i<ll(b);i++)
#define repr(i,a,b) for(ll i=a;i>=ll(b);i--)
#define endl "\n"
#define ALL(x) x.begin(),x.end()
#define ALLR(x) x.rbegin(),x.rend()
using namespace std;

string s, t;
int main() {
	cin >> s >> t;
	rep(i, 0, s.length()){
		if(s[i] != t[i]) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
    return 0;
}
