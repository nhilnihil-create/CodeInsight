#include <iostream>
#include <string>
using ll=long long;
#define rep(i,a,b) for(ll i=a;i<ll(b);i++)
#define repr(i,a,b) for(ll i=a;i>=ll(b);i--)
#define endl "\n"
#define ALL(x) x.begin(),x.end()
#define ALLR(x) x.rbegin(),x.rend()
using namespace std;

int k;
string s;
int main() {
	cin >> k >> s;
	int sl = s.length();
	if(sl > k){
		rep(i, 0, k) cout << s[i];
		cout << "..." << endl;
	}
	else {
		cout << s << endl;
	}
    return 0;
}
