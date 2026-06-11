#include <bits/stdc++.h>
using namespace std;
#define N 300005
int sum[N], cc[N], number[N];

void update(int *pen,int ind,int v) {
    while(ind<N) {
        pen[ind] += v;
        ind += ind&(-ind);
    }
}
int query(int *pen,int ind) {
    int ret = 0;
    while(ind>0) {
        ret += pen[ind];
        ind = ind&(ind-1);
    }
    return ret;
}
void solve() {
    int n;scanf("%d",&n);
    for(int i=0;i<n;++i) {
        int a;scanf("%d",&a);
        number[a]++;
    }
    int numType = 0;
    for(int i=1;i<=n;++i) {
        if(number[i]>0) {
            update(sum,number[i],number[i]);
            update(cc, number[i],1);
            ++numType;
        }
    }
    for(int k=1;k<=n;++k) {
        int l = 0,r = n/k,mid;
        while(l<r) {
            mid = (l+r+1)/2;
            int kCC = query(cc, mid);
            long long qsum = query(sum, mid);
            qsum += (long long)(numType-kCC)*mid;
            if(qsum>= mid*k) {
                l = mid;
            } else {
                r = mid-1;
            }
        }
        printf("%d ",l);
    }
    putchar('\n');
}
int main() {
    solve();
    return 0;
}