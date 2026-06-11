#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define REP(i,n) for (int i=1;i<=(n);i++)
typedef long long ll;

int main() {
    ll a,b,c;
    cin >> a >> b >> c;
    ll left = 4*a*b;
    ll d = (c-a-b);
    ll right = d*d;
    if(d>0&&left<right) cout << "Yes" << endl;
    else cout << "No" << endl;
}