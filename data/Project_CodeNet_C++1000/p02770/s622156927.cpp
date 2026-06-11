#include <bits/stdc++.h>
using namespace std;
int d[5002];
int main(){
    int k, q;
    scanf("%d%d", &k, &q);
    for(int i=0;i<k;i++) scanf("%d", &d[i]);
    for(int i=0;i<q;i++){
        int n, x, m;
        scanf("%d%d%d", &n, &x, &m);

        long long sum = 0;
        for(int j=0;j<k;j++){
            int d2 = d[j]%m;
            if(d2 == 0) d2 = m;
            sum += d2;
        }
        long long an = x%m;
        an += (n-1)/k*sum;
        for(int j=0;j<(n-1)%k;j++){
            int d2 = d[j]%m;
            if(d2 == 0) d2 = m;
            an += d2;
        }
        printf("%lld\n", n-1-an/m);
    }
}