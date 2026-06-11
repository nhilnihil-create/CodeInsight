#include <bits/stdc++.h>
using namespace std;
#define arep(i, x, n) for (int i = int(x); i < (int)(n); i++)
#define rep(i, n) for (long long i = 0; i < n; ++i)
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9 + 7
using ll = long long;

int main(){
    ll n;
    ll k;
    cin >> n >> k;

    ll fract1 = n % k;
    ll fract2 = abs(k - fract1);

    if(fract1 < fract2){
        cout << fract1 << endl;
    }else{
        cout << fract2 << endl;
    }
}