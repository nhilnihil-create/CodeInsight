#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





using ll = long long;

const ll mod = 1e9+7;
const int maxn = 1e6 + 5;





int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    int n;
    cin>>n;
    n *= 2;
    
    string s;
    cin>>s;
    
    vector<int> a(n, 0);
    for (int i=0; i<n; i++) {
	if (s[i]=='B') a[i]=1;
    }


    ll open = 0;
    ll ans = 1;

    for (int i=0; i<n; i++) {
	if ((a[i]+open)%2==0) {
	    ans=ans*open%mod;
	    open--;
	} else {
	    open++;
	}
	if (open<0 || open>n) out(0);
    }


    if (open != 0) out(0);


    // order of the operations
    n /= 2;
    for (int i=1; i<=n; i++) {
	ans=ans*i%mod;
    }

    cout<<ans<<endl;    
    return 0;
}
