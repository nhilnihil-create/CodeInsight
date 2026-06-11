#include <bits/stdc++.h>
using namespace std;
int a[55];
int main(){
    int n;
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%d", &a[i]);
    }
    sort(a+1, a+1+n);
    double ans = a[1];
    for(int i=2;i<=n;i++) ans = (ans + a[i])/2;
    printf("%.10lf\n", ans);
}