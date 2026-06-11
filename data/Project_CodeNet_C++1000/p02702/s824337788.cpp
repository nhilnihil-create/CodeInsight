#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iostream>
#include <cstdlib>
using namespace std;

const int mod = 2019;

char p[200010];
int a[200010], b[200010], s[200010];

int main() {
    int n;
    cin>>(p+1);
    n = strlen(p + 1);
    int c = 1, now = 0;
    long long ans = 0;
    for(int i = 1; i <= n; i++) a[i] = p[i] - '0';
    s[0] = 1;
    for(int i = n; i >= 1; i--) {
        now += a[i] * c;
        c *= 10;
        now %= mod;
        c %= mod;
        ans += s[now];
        //if(s[now] > 0) printf("%d\n", i);
        s[now]++;
    }
    cout<<ans<<endl;

    return 0;
}
