#include<bits/stdc++.h>
#include <immintrin.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define repo(i,o,n) for(int i=o;i<(int)(n);++i)

int n,l[2000],ans;

int main() {
    scanf("%d", &n);
    rep(i,n) scanf("%d", &l[i]);
    sort(l,l+n);
    rep(i,n) repo(j,i+1,n) repo(k,j+1,n) if (l[k] < l[i]+l[j]) ans++;
    printf("%d\n", ans);
}
