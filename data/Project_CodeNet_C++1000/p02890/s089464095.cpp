#include <bits/stdc++.h>
using namespace std;
int cnt[300002], cnt2[300002], sum[300002];
int main(){
    int n, a;
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%d", &a);
        cnt[a]++;
    }
    for(int i=1;i<=n;i++) cnt2[cnt[i]]++;
    for(int i=1;i<=n;i++) sum[i] = sum[i-1] + cnt2[i]*i;
    for(int i=n-1;i>=1;i--) cnt2[i] += cnt2[i+1];
    for(int k=1;k<=n;k++){
        int ans = 0;
        for(int i=1;i<=n/k;i++){
            int rem = sum[i] + cnt2[i+1]*i;
            if(k*i <= rem) ans = i;
        }
        printf("%d\n", ans);
    }
}