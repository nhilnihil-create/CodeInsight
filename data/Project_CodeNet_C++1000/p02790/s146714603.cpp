#include <bits/stdc++.h>
#define rep(i, n)for(int i=0,i<(n);++i)
using namespace std;
using ll = long long;

int main(){
 int a, b;
 cin >> a >> b;
 int n = min(a, b);
 int m = max(a,b);
 string ans;
 for(int i =0; i< m; i++) ans += to_string(n);
 cout << ans << endl;
 return 0;
}