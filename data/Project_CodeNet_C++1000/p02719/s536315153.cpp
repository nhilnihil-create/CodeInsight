#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define EPS 1e-6
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 10;


int main()
{
    LL n, k;
    while(cin >> n >> k){
        LL mod = n % k;
        cout << min(mod, k - mod) << endl;
    }
}
