#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
#define mp make_pair
// GCD inbuilt func: __gcd(a,b)
// LCM formula: (a*b)/__gcd(a,b)

int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
	// CODE goes here
    int x,y;
    cin >> x >> y;
    if(y%2 || y>4*x || y<2*x) cout << "No\n";
    else cout << "Yes\n";
	return 0;
}
