#include<bits/stdc++.h>
#define xx first
#define yy second
#define ll long long
using namespace std;
 
const int N = 200000 + 5;
int a[N], n, cnt;
int ans[N];
 
int main () {
    scanf ("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf ("%d", &a[i]);
    }
    for (int i = n; i >= 1; --i) {
        int tmp = 0;
        for (int j = n / i; j >= 1; --j) {
            tmp ^= ans[j * i];
        }
        ans[i] = tmp ^ a[i];
        cnt += ans[i];
    }
    printf ("%d\n", cnt);
    for (int i = 1; i <= n; ++i) {
        if (!ans[i]) {continue;}
        printf ("%d ", i);
    }
    return 0;
}