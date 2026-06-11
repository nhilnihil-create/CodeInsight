#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=mod*mod*3LL;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    ll b[n];
    ll a[n];
    ll sum = 0;
    for(int i=0;i<n;i++){
    	cin >> a[i];
    	if(i % 2 == 0) sum += a[i];
    	else sum -= a[i];
    }
    b[0] = sum;
    for(int i=1;i<n;i++){
    	b[i] = (a[i-1] - b[i-1] / 2) * 2;
    }
    for(int i=0;i<n;i++){
    	cout << b[i] << " ";
    }
    cout << endl;
    return 0;
}
