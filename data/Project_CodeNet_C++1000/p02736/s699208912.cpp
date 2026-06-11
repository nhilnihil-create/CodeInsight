#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e6+5;
int n, ans, flg; char a[N];
int main()
{
    scanf("%d%s", &n, a); for(int i = 0; i < n; ++i) if((a[i] -= '1') == 1) flg = 1;
    if(!flg) for(int i = 0; i < n; ++i) a[i] >>= 1;
    for(int i = 0; i < n; ++i) if(((n-1)&i) == i) ans ^= a[i]&1;
    printf("%d\n", ans<<!flg);
    return 0;
}