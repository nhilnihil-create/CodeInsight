#include <iostream>
using ll=long long;
#define rep(i,a,b) for(ll i=a;i<ll(b);i++)
#define repr(i,a,b) for(ll i=a;i>=ll(b);i--)
#define endl "\n"
#define ALL(x) x.begin(),x.end()
#define ALLR(x) x.rbegin(),x.rend()
using namespace std;

int x[5];
int main() {
	rep(i, 0, 5) cin >> x[i];
	rep(i, 0, 5) if(x[i] == 0) cout << i+1 << endl;
    return 0;
}
