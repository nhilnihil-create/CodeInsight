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
    int n, x, t; cin >> n >> x >> t;

    if(n%x) cout << (n/x+1)*t << endl;
    else cout << n/x*t << endl;

    return 0;
}