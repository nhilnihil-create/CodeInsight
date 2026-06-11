#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





using ll = long long;

const ll mod = 1e9+7;
const int maxn = 1e6 + 5;



const int inf = 2e9;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    int n, m, k;
    cin>>n>>m>>k;
    vector<ll> a(n+1), b(m+1);
    for (int i=0; i<n; i++) {
	cin>>a[i+1];
	a[i+1]+=a[i];
    }
    for (int i=0; i<m; i++) {
	cin>>b[i+1];
	b[i+1]+=b[i];
    }

    int res = 0;
    for (int i=0; i<=n && a[i]<=k; i++) {
	int j = prev(upper_bound(b.begin(),b.end(),k-a[i]))-b.begin();
	//cout<<i<<": "<<j<<endl;
	res=max(res,i+j);
    }

    cout<<res<<endl;
  
    return 0;
}
