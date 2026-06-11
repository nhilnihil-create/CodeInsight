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
    V<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    V<int> b = a;
    sort(ALL(b));

    for(int i = 0; i < n; i++){
        if(a[i] == b[n - 1]){
            cout << b[n - 2] << endl;
        }else{
            cout << b[n - 1] << endl;
        }
    }

    return 0;
}
