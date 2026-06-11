#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    ll n,a,b;
    cin >> n >> a >> b;
    // n%(a+b)
    ll per = n/(a+b);
    n %= (a+b);
    if(n <= a) cout << n+per*a << endl;
    else cout << a+per*a << endl;
    return 0;
}