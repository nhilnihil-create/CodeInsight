#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
ll n;
cin >> n;
vector<ll> a(n);
for(ll i=0;i<n; i++)cin >> a[i];
ll b[200005]={0};
for(ll i=0;i<n; i++) b[a[i]]++;
ll ans = 0;
for(ll i=0;i<200005; i++) {
   ll m = b[i];
   if(m>=2) ans += m*(m-1) / 2;
}
for(ll i=0;i<n; i++){
   ll sum = ans;
   sum -= b[a[i]]-1;
cout << sum << endl;
}
 return 0;
}