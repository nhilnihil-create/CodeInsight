#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;
 
const int N = 5e5 + 5;
 
int n;
char s[N];
int L[N], R[N];
 
int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1) + 1;
    for (int i = 1; i <= n; i++)
        L[i] = (s[i - 1] == '<') * (L[i - 1] + 1);
    for (int i = n; i; i--)
        R[i] = (s[i] == '>') * (R[i + 1] + 1);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += max(L[i], R[i]);
//      cerr << max(L[i], R[i]) << ' ';
    }
    printf("%lld\n", ans);
    return 0;
}