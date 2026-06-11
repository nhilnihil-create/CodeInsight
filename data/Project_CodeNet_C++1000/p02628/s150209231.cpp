#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int n,k;cin>>n>>k;
    int a[n];rep(i,n)cin>>a[i];
    sort(a,a+n);
    int ans = 0;
    rep(i,k)ans+=a[i];
    cout<<ans<<endl;
	return 0;
}