#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e6+10;

int a[maxn];
int c[maxn];
char s[maxn];

int cnt2(int x) {
    int res = 0;
    while(x%2==0) {
        x >>= 1;
        res++;
    }
    return res;
}

int main() {
    int n;
    scanf("%d%s", &n, s+1);
    for(int i=1; i<=n; i++)
        a[i] = s[i]-'1';
    c[0] = 0;
    for(int i=1; i<=n-1; i++)
        c[i] = c[i-1]+cnt2(n-i)-cnt2(i);
    for(int i=0; i<=n-1; i++) {
        if(c[i])
            c[i] = 0;
        else
            c[i] = 1;
    }
    int ans = 0;
    for(int i=1; i<=n; i++)
        ans ^= a[i]*c[i-1]%2;
    if(ans&1) {
        printf("1\n");
        return 0;
    }
    bool flag = false;
    for(int i=1; i<=n; i++) {
        if(a[i]==1) {
            flag = true;
            break;
        }
    }
    if(flag)
        printf("0\n");
    else {
        ans = 0;
        for(int i=1; i<=n; i++)
            ans ^= a[i]/2*c[i-1]%2;
        if(ans&1)
            printf("2\n");
        else
            printf("0\n");
    }
    return 0;
}
