#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    ll a,b;
    cin >> a >> b;
    cout << a*b/__gcd(a,b) << endl;
    return 0;
}