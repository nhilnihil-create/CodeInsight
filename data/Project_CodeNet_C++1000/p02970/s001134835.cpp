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
    int n, d; cin >> n >> d;

    int a = d * 2 + 1;
    int b = n / a;
    if(n <= b * a){
        cout << n / a << endl;
    }else{
        cout << n / a + 1 << endl;
    }

    return 0;
}
