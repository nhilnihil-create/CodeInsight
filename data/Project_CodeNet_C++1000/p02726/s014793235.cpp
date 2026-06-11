#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn = 2010;

int n, x, y;
int ans[maxn];

int main() {
    int len;
    scanf("%d%d%d", &n, &x, &y);
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (i <= x) {
                len = min(j - i, x - i + 1 + abs(y - j));
            } else {
                len = min(j - i, i - x + 1 + abs(y - j));
            }
            ans[len]++;
        }
    }
    for(int i=1;i<n;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}