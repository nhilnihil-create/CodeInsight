#include <iostream>
using ll=long long;
#define rep(i,a,b) for(ll i=a;i<ll(b);i++)
#define repr(i,a,b) for(ll i=a;i>=ll(b);i--)
#define endl "\n"
#define ALL(x) x.begin(),x.end()
#define ALLR(x) x.rbegin(),x.rend()
using namespace std;

int x, y;
bool flag;
int main() {
	cin >> x >> y;

	if(y%2 != 0) flag = true;
	if(!(2*x <= y && y <= 4*x)) flag = true;

	if(flag) cout << "No" << endl;
	else cout << "Yes" << endl;
    return 0;
}
