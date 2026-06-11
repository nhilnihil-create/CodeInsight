#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
const ll mod = 1000000007;

int main() {
    int n,d;
    cin >> n >> d;
    int c = 2*d+1;
    cout << (n+c-1)/c << endl;
    return 0;
}
