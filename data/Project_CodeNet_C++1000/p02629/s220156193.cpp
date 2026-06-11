#include <iostream>
#include <string>
using ll=long long;
#define rep(i,a,b) for(ll i=a;i<ll(b);i++)
#define repr(i,a,b) for(ll i=a;i>=ll(b);i--)
#define endl "\n"
#define ALL(x) x.begin(),x.end()
#define ALLR(x) x.rbegin(),x.rend()
using namespace std;

ll n;
string ans;
int main() {
	cin >> n;
	while(n>26){
		n--;
		ans += (n%26) + 'a';
		n /= 26;
	}
	ans += n-1+'a';
	reverse(ALL(ans));
	cout <<  ans << endl;
    return 0;
}
