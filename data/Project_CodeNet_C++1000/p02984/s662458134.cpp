#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000007
//0=48,A=65,a=97

int main() {
    int n;cin >> n;
    ll sum=0;
    vector<ll> a(n);
    for(int i=0;i<n;i++) {
        cin >> a[i];
        sum += a[i];
    }

    vector<ll> ans(n);
    for(int i = 1; i < n; i+= 2) {
        sum -= 2*a[i];
    }
    ans[0]=sum;

    for(int i = 1; i < n; i++) {
        ans[i]=2 * a[i-1] -ans[i-1];
    }

    for(int i = 0; i < n-1; i++) {
        cout << ans[i] << ' ';
    }
    cout << ans[n-1] << endl;

    return 0;
}