#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
    int n;
    cin >> n;
    if(n<=99) cout << min(9,n) << endl;
    else if(n<=999) cout << n-90 << endl;
    else if(n<=9999) cout << 909 << endl;
    else if(n<=99999) cout << 909+n-9999 << endl;
    else cout << 90909 << endl;
}