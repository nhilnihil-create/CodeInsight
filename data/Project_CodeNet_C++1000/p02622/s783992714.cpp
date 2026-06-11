#include <iostream>
#include <string>
using ll=long long;
#define rep(i,a,b) for(ll i=a;i<ll(b);i++)
#define repr(i,a,b) for(ll i=a;i>=ll(b);i--)
#define endl "\n"
#define ALL(x) x.begin(),x.end()
using namespace std;

string s, t;
int ans;
int main() {
	cin >> s >> t;
	int lengh = s.length();
	rep(i, 0, lengh) if(s[i] != t[i]) ans++;
	cout << ans << endl;
    return 0;
}
