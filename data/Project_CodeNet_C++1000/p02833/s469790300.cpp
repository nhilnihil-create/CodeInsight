#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <stdio.h>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

int main() {

    ll N;
    cin >> N;
    ll out = 0;
    if(N%2==0){
        ll n = N;
        n = N/10;
        out += n;
        while(n>0){
            n /= 5;
            out += n;
        }
    }
    cout << out << endl;
    return 0;
}
