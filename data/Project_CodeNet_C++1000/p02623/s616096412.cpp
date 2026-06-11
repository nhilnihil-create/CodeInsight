#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef long long ll;


int main(){
	int n,m;
    ll k;
    vector<ll> a(200000),b(200000);

    cin >> n >> m >> k;
    for(int i=0;i<n;i++)cin >> a[i];
    for(int i=0;i<m;i++)cin >> b[i];

    vector<ll> suma(n+1),sumb(m+1);
    suma[0] = 0;
    sumb[0] = 0;
    for(int i=0;i<n;i++) suma[i+1] = suma[i] + a[i];
    for(int i=0;i<m;i++) sumb[i+1] = sumb[i] + b[i];

    int ans = 0;
    for(int i=0;i<=n&&suma[i]<=k;i++){
        int j = upper_bound(sumb.begin(),sumb.end(),k-suma[i]) - sumb.begin() -1;
        ans = max(i+j,ans);
    }

    cout << ans << endl;

	return 0;
}
