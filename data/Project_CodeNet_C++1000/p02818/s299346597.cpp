#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}


int main() {
    ll a,b,k;
    cin >> a >> b >> k;
    if(a-k>=0) {
        a -= k;
        cout << a << " " << b << endl;
        return 0;
    } else {
        k -= a;
        a = 0;
        if(b-k >= 0) {
            b -= k;
            cout << a << " " << b << endl;
            return 0;
        } else {
            b = 0;
            cout << a <<" " << b << endl;
            return 0;
        }
    }
}