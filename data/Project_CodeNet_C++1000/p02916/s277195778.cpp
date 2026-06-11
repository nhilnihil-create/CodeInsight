#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





using ll = long long;

const ll mod = 1e9+7;
const int maxn = 1e6 + 5;



int n,a[maxn],b[maxn],c[maxn];


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    cin>>n;
    for (int i=0; i<n; i++) {
	cin>>a[i]; 
    }
    for (int i=1; i<=n; i++) {
	cin>>b[i];
    }
    for (int i=1; i<=n; i++) {
	cin>>c[i];
    }

    int res=0;
    for (int i=0; i<n; i++) {
	res+=b[a[i]];
	if (i && a[i-1]+1==a[i]) {
	    res+=c[a[i-1]];
	}
    }
    out(res);
    
    
    return 0;
}
