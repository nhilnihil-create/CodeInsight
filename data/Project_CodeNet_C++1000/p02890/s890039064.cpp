#include<bits/stdc++.h>

#define ll long long
#define INF 2147483647

int inp(){
    char c = getchar();
    while(c < '0' || c > '9')
        c = getchar();
    int sum = 0;
    while(c >= '0' && c <= '9'){
        sum = sum * 10 + c - '0';
        c = getchar();
    }
    return sum;
}

int a[300010], n;
ll sum[300010];
int ans[300010];

bool check(int num, int lim){
    int mid = std::lower_bound(a + 1, a + n + 1, lim) - a;
    num -= n - mid + 1;
    // printf("mid = %d\n", mid);
    return sum[mid - 1] >= num * lim;
}

int main(){
    n = inp();
    for(int i = 1; i <= n; i++)
        a[inp()]++;
    std::sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + a[i];
    for(int i = n; i >= 1; i--){
        ans[i] = ans[i + 1];
        while(check(i, ans[i] + 1))
            ans[i]++;
    }
    for(int i = 1; i <= n; i++)
        printf("%d\n", ans[i]);
}