#include <bits/stdc++.h>
#include <cstdio>
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
    double sum = 0;
    for(int i = 0; i < n; i++){
        double a; cin >> a;
        sum += 1 / a;
    }
    printf("%.10f\n", 1 / sum);

    return 0;
}
