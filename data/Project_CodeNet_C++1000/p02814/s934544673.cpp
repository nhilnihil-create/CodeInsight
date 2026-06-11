#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define sqr(x) (x)*(x)
using namespace std;

ll lcm(ll a, ll b){
	return a*b/__gcd(a,b);
}

int main(){
#ifdef LOCAL
    freopen("inp.txt", "r", stdin );
    freopen("ans.txt", "w", stdout);
#endif
    ll n, m;
    cin >> n >> m;
    vector<int>a(n);
    for(int i=0; i<n; i++){
    	cin >> a[i];
    	a[i] /= 2;
    }
    ll l = a[0];
    for(int i=1; i<n; i++){
    	l = lcm(l, a[i]);
    }
    for(int i=0; i<n; i++){
    	if((l / a[i]) % 2 == 0){
    		cout << 0 << '\n';
    		return 0;
    	}
    }
    cout << m/(l*2) + (m/l)%2 << '\n';
}
