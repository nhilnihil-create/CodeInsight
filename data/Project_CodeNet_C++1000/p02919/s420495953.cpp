#pragma GCC optimize(2)
#pragma commet(linker,"STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
const int man = 1e5+10;
int x[man];
int l[man],r[man];
int pos[man];
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<= n;i++){
        scanf("%d",&x[i]);
        pos[x[i]] = i;
        l[i] = i-1;
        r[i] = i+1;
    }
    long long ans = 0;
    for(int i = 1;i <= n;i++){
        int lpos1 = l[pos[i]];
        int lpos2 = l[lpos1];
        int rpos1 = r[pos[i]];
        int rpos2 = r[rpos1];
        if(lpos1)ans += 1ll*(lpos1 - lpos2)*(rpos1 - pos[i])*i;
        if(rpos1!=n+1)ans += 1ll*(rpos2 - rpos1)*(pos[i] - lpos1)*i;
        l[rpos1] = lpos1;
        r[lpos1] = rpos1;
    }
    printf("%lld\n",ans);
    return 0;
}