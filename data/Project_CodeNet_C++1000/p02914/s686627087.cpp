#include <bits/stdc++.h>

using namespace std;
#define ll long long

#define N 100005
ll in[N];
void solve() {
    ll ret = 0;
    int n;scanf("%d",&n);
    for(int i=0;i<n;++i) {
        scanf("%lld",&in[i]);
        ret ^=in[i];
    }
    for(int i=0;i<n;++i) {
        ll tmp = in[i]&ret;
        in[i] -= tmp;
    }
    sort(in,in+n,greater<ll>());
    int pos = 0;
    for(int i=60;i>=0;--i) {
        int ind = -1;ll tmp = -1e18;
        for(int j=pos;j<n;++j) {
            if(in[j]&(1LL<<i)   && tmp<in[j]) {
                swap(in[pos],in[j]);
                tmp = in[j];
                break;
            }
        }
        if(tmp==-1e18) {
            int cc = 0;
            for(int j = 0;j<pos;++j) {
                if(in[j]&(1LL<<i)) {
                    ++cc;
                }
            }
            if(cc&1) {
                ret += (1LL<<i)*2;
            }
            continue;
        }
        ll org = in[pos];
        in[ind] = 0;
        ret += (1LL<<i)*2;
        for(int j=0;j<n;++j) {
            if(in[j]&(1LL<<i) && j!=pos) {
                in[j]^= org;
            }
        }
        ++pos;
    }
    printf("%lld\n",ret);
}
int main() {
    //freopen("input.txt","r",stdin);
    solve();
    return 0;
}