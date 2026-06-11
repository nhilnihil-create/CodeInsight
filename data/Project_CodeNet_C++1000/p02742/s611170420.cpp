#include <bits/stdc++.h>
using namespace std;
#define arep(i, x, n) for (int i = int(x); i < (int)(n); i++)
#define rep(i, n) for (long long i = 0; i < n; ++i)
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9 + 7
using ll = long long;

int main(){
    ll H;
    ll W;
    cin >> H >> W;

    ll sum = H * W;
    if((H == 1) || (W == 1)) sum = 1;
    else if(sum % 2 == 0) sum = sum / 2;
    else sum = sum / 2 + 1;

    cout << sum << endl;

}