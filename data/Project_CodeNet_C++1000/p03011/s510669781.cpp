#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0; (i)<(n); (i)++)
#define all(v) (v).begin(), (v).end()

int main() {
    int p,q,r;
    cin >> p >> q >> r;

    int s = p+q+r;
    cout << s-max(p,max(q,r));
}