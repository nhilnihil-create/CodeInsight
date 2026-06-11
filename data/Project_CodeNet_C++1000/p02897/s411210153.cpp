#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
    cout << fixed << setprecision(7);
    int n;
    cin >> n;
    double a=n;
    if(n%2==0) cout << 0.5 << endl;
    else cout << (a+1)/2/a << endl;
}