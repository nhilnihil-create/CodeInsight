#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

int main(){
    ll n, a, b;
    cin >> n >> a >> b;
    if ((a+b) % 2 == 0) {
        cout << abs(a - (b + a) / 2) << endl;
        return 0;
    }
    cout << min(a-1, n-b) + 1 + ((b - a - 1) / 2) << endl;

    return 0;
}