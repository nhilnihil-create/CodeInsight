#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll S;
    cin >> S;
    ll x1 = 1e9;
    ll y2 = (S+x1-1)/x1;
    ll x2 = x1*y2 - S;
    cerr << abs(x1*y2 - x2) << endl;
    cout << "0 0 " << x1 << " 1 " << x2 << " " << y2 << endl;
    return 0;
}