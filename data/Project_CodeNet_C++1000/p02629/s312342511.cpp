#include <iostream>
#include <cstdio>
using namespace std;
long long n;
void DFS(long long x) {
        if (!x) return;
        x--;
        DFS(x/26);
        cout<<(char)('a'+x%26);
        return;
}
signed main()
{
        scanf("%lld",&n);
        DFS(n);
        return 0;
}
