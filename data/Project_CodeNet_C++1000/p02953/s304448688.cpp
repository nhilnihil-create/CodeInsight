#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
#define ld long double
#define ll long long
#define mod 1000000007
#define IINF INT_MAX
#define INF 1LL << 30


int main() {
    int n; cin >> n;
    V<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    for(int i = n - 1; i > 0; i--){
        if(a[i] < a[i - 1]){
            a[i - 1]--;
        }
    }

    for(int i = n - 1; i > 0; i--){
        if(a[i] < a[i - 1]){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;


    return 0;
}
