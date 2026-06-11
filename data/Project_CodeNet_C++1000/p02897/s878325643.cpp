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
    int n; cin >> n;

    int m = n;
    if(m & 1){
        m /= 2;
        m++;
        cout << setprecision(10) << (double)m / (double)n << endl;
    }else{
        m /= 2;
        cout << setprecision(10) << (double)m / (double)n << endl;
    }

    return 0;
}
