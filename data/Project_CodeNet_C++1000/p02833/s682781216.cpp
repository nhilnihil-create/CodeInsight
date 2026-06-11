#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define MIN(a,b) ((a)>(b)? (b): (a))
#define MAX(a,b) ((a)<(b)? (b): (a))

const long long INF = 1LL << 60;
typedef unsigned long long ll;
const long long MOD = 1000000000 + 7;

int main() {
    ll n;
    cin >> n;
    if (n%2 == 1) {
        cout << 0 << endl;
        return 0;
    }
    ll out=0;
    ll divide = 10;
    while (divide <= n) {
        out += n/divide;
        divide*= 5;
    }
    cout << out << endl;
    return 0;
}