#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
#define ld long double
#define ll long long
#define mod 1000000007
#define IINF INT_MAX
#define INF 1LL << 30


int main() {
    V<int> v(3);
    for(int i = 0; i < 3; i++) cin >> v[i];

    sort(ALL(v));

    cout << v[0] + v[1] << endl;
    return 0;
}
