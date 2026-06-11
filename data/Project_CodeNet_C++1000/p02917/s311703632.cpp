#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
int n;
cin >> n;
vector<int> a(n),b(n-1);
for(int i= 0; i< n-1; i++)cin >> b[i];
a[0] = b[0];
for(int i = 0; i< n-1; i++)a[i+1]=b[i];
 for(int i = 0; i< n-2; i++){
     if(b[i]>b[i+1])a[i+1]=b[i+1];
 }
ll ans = 0;
for(int i = 0; i< n; i++)ans += a[i];
cout << ans << endl;
return 0;
}