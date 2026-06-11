#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n, l;
int main() {
   cin >> n >> l;
   if (l>=0) cout << (2*l+n)*(n-1)/2;
   else if (n>abs(l)) cout << (2*l+n-1)*n/2;
   else cout << (2*l+n-2)*(n-1)/2;
}