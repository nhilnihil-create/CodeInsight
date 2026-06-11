#include <bits/stdc++.h>
#define repr(i,from,to) for(int (i)=(from);(i)<(to);(i)++)
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
#define vprint(x) for(auto a:(x)) cout << x << endl;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) { a = b; return true;}
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) { a = b; return true;}
    return false;
}
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll t[2], a[2], b[2];cin>>t[0]>>t[1]>>a[0]>>a[1]>>b[0]>>b[1];
    if (t[0]*a[0]+t[1]*a[1] == t[0]*b[0] + t[1]*b[1]) {
        cout << "infinity" << endl;
    } else if (a[0] > b[0] && t[0]*a[0]+t[1]*a[1] > t[0]*b[0]+t[1]*b[1]
            || b[0] > a[0] && t[0]*a[0]+t[1]*a[1] < t[0]*b[0]+t[1]*b[1]) {
        cout << 0 << endl;
    } else {
        ll diff = abs(t[0]*a[0]+t[1]*a[1] - (t[0]*b[0]+t[1]*b[1]));
        ll diff1 = abs(a[0]-b[0]) * t[0];
        DEBUG{
            cout << diff << " " << diff1 << endl;
        }
        if (diff1%diff==0) {
            cout << diff1/diff * 2  << endl;
        } else{
        cout << diff1 / diff * 2 + 1 << endl;

        }
    }

    return 0;
}
