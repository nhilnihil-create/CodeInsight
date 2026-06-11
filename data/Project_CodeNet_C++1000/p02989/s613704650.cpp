#include <bits/stdc++.h>
using namespace std;
int a[100001];
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n + 1);
    printf("%d", a[n / 2 + 1] - a[n / 2]);
    return 0;
}
