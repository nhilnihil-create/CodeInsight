#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define loop(i, a, n) for(int i = (a); i < (n); i++)
#ifdef _DEBUG
#define dd(x) cout << #x << " : " << x << endl
#else
#define dd(x)
#endif
using namespace std;
using ll = int64_t;

int main(){
    ll a, b, k; cin >> a >> b >> k;

    if(k <= a) {
        cout << a-k << ' ' << b << endl;
    } else if(k <= a+b) {
        cout << 0 << ' ' << b-k+a << endl;
    } else {
        cout << 0 << ' ' << 0 << endl;
    }

    return 0;
}
