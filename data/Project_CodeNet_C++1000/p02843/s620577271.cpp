#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll X;
    cin >> X;
    ll n = X/100;
    ll m = X - 100*n;
    if(m <= 5*n)cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
}