#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int n, m, a[N], b[N]; map<int, int> h;
int main()
{
    scanf("%d", &n); for(int i = 1; i <= n; ++i) scanf("%d", a+i), b[i] = a[i], ++h[b[i]];
    sort(b+1, b+n+1), m = unique(b+1, b+n+1)-b-1;
    if(m == 1&&b[1] == 0) return puts("Yes"), 0;
    else if(n%3) return puts("No"), 0;
    else if(m == 2&&h[0] == n/3) return puts("Yes"), 0;
    else if(m == 3&&(b[1]^b[2]^b[3]) == 0&&h[b[1]] == n/3&&h[b[2]] == n/3) return puts("Yes"), 0;
    puts("No");
    return 0;
}