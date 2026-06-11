#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int INF = 1001001001;

#define rep(i, n)  for(int i=0;i<(n);++i)
#define all(x) (x).begin(),(x).end()

int main() {
    int n;
    cin >> n;
    if(n % 2 == 0) n -= 1;
    int ans = n / 2;
    cout << ans << endl;
}