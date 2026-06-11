#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define REP(i,n) for (int i=1;i<=(n);i++)
typedef long long ll;

int main() {
    ll n,a,b;
    cin >> n >> a >> b;
    ll c = n/(a+b)*a;
    ll d = n%(a+b);
    if(d>a) d=a;
    cout << c+d << endl;
}