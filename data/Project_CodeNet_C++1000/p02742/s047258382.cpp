#include <iostream>
#include <cmath>
#include <string.h>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define INF 100000000;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
int main(){
    ll A,B;
    cin >> A >> B;
    ll ans = A * B / 2;
    if (A % 2 != 0 && B % 2 != 0){
        ans++;
    }
    if (A == 1 || B == 1) ans = 1;
    cout << ans << endl;
    return 0;
}