#include <iostream>
#include <string>
using ll=long long;
#define rep(i,a,b) for(ll i=a;i<ll(b);i++)
#define repr(i,a,b) for(ll i=a;i>=ll(b);i--)
#define endl "\n"
#define ALL(x) x.begin(),x.end()
#define ALLR(x) x.rbegin(),x.rend()
using namespace std;

string n;
int main() {
	cin >> n;
	switch (n[n.size()-1]) {
		case '3':
			cout << "bon" << endl;
			break;
		case '0':
		case '1':
		case '6':
		case '8':
			cout << "pon" << endl;
			break;
		default:
			cout << "hon" << endl;
	}
    return 0;
}
