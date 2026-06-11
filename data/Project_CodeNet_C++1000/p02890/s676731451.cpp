#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int ct[n];
    memset(ct,0,sizeof(ct));
    for (int i = 0; i < n; i++){
        int x;
        scanf("%d",&x);
        ct[--x]++;
    }
    int a[n+1];
    memset(a,0,sizeof(a));
    for (int i = 0; i < n; i++){
        if (ct[i]) a[ct[i]]++;
    }
    int total = n;
    int cur = n;
    for (int i = 1; i <= n; i++){
        while (total < i*cur){
            total -= a[cur];
            a[cur-1] += a[cur];
            a[cur] = 0;
            cur--;
        }
        printf("%d\n",cur);
    }

}
