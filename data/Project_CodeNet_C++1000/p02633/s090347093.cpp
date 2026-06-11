#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (int)(n); ++i)
typedef long long ll;

const int mod = 1e9+7;
const int INF = 2000000;
const double PI = acos(-1.0);

int main() {
    
    int X;
    cin >> X;
    int K = 1;
    while(X*K%360 != 0) K++;
    cout << K << endl;
}