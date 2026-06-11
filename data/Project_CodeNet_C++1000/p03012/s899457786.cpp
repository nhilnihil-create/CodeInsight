#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
int n;
cin >>n;
vector<int> w(n);
for(int i = 0; i< n; i++)cin >> w[i];
vector<int> a(n);
int t;
a[0] = w[0];
for(int i = 1; i<n;i++) a[i] += a[i-1]+w[i];
int ans =100100 ;
for(int t=0; t< n-1;t++){
   ans = min(ans, abs(a[t] -(a[n-1]-a[t])));
}

cout << ans << endl;
return 0;
}
