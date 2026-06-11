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
    long double w, h, x, y; cin >> w >> h >> x >> y;

    if(x * 2 == w && y * 2 == h){
        printf("%.10Lf", w * h / 2);
        cout << ' ' << 1 << endl;
    }else{
        printf("%.10Lf", w * h / 2);
        cout << ' ' << 0 << endl;
    }

    return 0;
}
