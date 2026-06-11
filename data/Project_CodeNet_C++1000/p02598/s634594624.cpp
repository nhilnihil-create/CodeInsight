#include <bits/stdc++.h>

const int N = 200010;
using ll = long long;

int a[N];

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    int left = 1, right = int(1e9) + 10;
    while (left < right){
        int mid = (left + right) / 2;
        ll sum = 0;
        for (int i = 0; i < n; ++ i){
            sum += (a[i] - 1) / mid;
        }
        if (sum > k){
            left = mid + 1;
        }
        else{
            right = mid;
        }
    }
    printf("%d\n", left);
    return 0;
}