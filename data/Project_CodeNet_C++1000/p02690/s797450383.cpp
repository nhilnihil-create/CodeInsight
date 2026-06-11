#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define PI 3.141592
#define MOD7 1000000007
#define LL_INF 9000000000000000000
#define LL_MINF -9000000000000000000
#define INT_INF 2000000000
#define INT_MINF -2000000000
#define all(a) (a).begin(), (a).end()
#define fi first
#define se second
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};


int main(){
    ll X;
    cin >> X;
    for(ll a = -200; a <= 200; a++){
        for(ll b = -200; b <= 200; b++){
            if(pow(a, 5) - pow(b, 5) == X){
                cout << a << ' ' << b << endl;
                return 0;
            }
        }
    }
}