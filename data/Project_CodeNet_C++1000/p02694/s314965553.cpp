#include <queue>
#include <cstdio>
#include <iostream>
#include <math.h>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <stack>
#include <time.h>
#include <functional>

//#include "All.h"

using namespace std;
typedef long long int ll;

#define EPS (1e-9)
#define INF (1e9)
#define PI (acos(-1))
#define REP(i,n) for(int i=0;i<n;i++)

int gcd(int a, int b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll beki(ll a, ll b) {
    ll tmp = 1;
    REP(i, b) tmp *= a;
    return tmp;
}

ll X;

int main() {
    cin >> X;
    float f = 1.01;
    ll okane = 100;
    //float F = f;
    REP(i, INF) {
        okane += okane / 100;
        if (okane >= X) {
            cout << i + 1 << endl;
            return 0;
        }
        //F *= f;
    }
    
}

/*
10 10 2
1 10 9 1
2 10 9 2
*/