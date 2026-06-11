#include <bits/stdc++.h>
using namespace std;
int a[105];
int main(){
    int n;
    scanf("%d", &n);
    double ans = 0;
    for(int i=1;i<=n;i++){
        scanf("%d", &a[i]);
        ans += 1.0/a[i];
    }
    printf("%.10lf\n", 1/ans);
}