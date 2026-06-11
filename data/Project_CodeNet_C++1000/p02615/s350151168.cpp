#include <bits/stdc++.h>
#define ll long long int
#define forr(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
#define oo 1000000000000000000LL
using namespace std;



void _sol(){
    int n; cin >> n;
    int a[n];
    forr(i,n) cin >> a[i];
    sort(a,a+n,greater<int>());
    ll ans = a[0] , i=1;
    n-=2;
    while(n>0){
        ans = (ans + (ll)a[i]*min(2LL,(ll)n));
        n-=2;
        i++;
    }
    cout << ans;
    
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1; //cin >> t;
    while(t--) _sol();
}
