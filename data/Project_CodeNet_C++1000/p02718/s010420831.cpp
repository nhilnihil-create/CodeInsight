#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    ll n,m;
    cin >> n >> m;  // n: 4 m:1
    ll ai;
    double s=0.;
    int A[n];
    for (ll i=0;i<n;i++){  // i 3
        cin >> ai;  // ai 1
        A[i] = ai;  // A: [5,4,2,1]
        s += ai;  // 12.0
    }
    ll cnt=0;
    double needed=s/(4*m);  // needed: 3.0
    for (ll i=0;i<n;i++){  // i: 3
        if (A[i] >= needed) cnt++;  // 2
    }
    if (cnt >= m) cout << "Yes" << endl;
    else cout << "No" << endl;
}