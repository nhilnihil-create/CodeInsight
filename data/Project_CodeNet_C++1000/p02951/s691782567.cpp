#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
const ll mod = 1000000007;

int main() {
    int a,b,c;
    cin >> a >> b >> c;
    cout << max(c-(a-b),0) << endl;
}
