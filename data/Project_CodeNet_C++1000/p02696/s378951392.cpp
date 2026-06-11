#include <bits/stdc++.h>
using namespace std;
int main(){
    long a,b,n;
    cin >> a >> b >> n;
    long m = min(b-1,n);
    long ans = a*m/b;
    cout << ans << endl;
 }