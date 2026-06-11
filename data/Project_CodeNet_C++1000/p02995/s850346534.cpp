#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

ll a, b, c, d, sum;

int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a % b);
}

int main() {
    cin >> a >> b >> c >> d;
    sum+=b/c-(a-1)/c;
    sum+=b/d-(a-1)/d;
    int e=gcd(c,d);
    sum-=b/(c*d/e)-(a-1)/(c*d/e);
    cout<<b-a+1-sum<<endl;
    return 0;
}
