#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 200000 + 10;
int R[MAX];

int main()
{
    int n;
    while (scanf("%d", &n) == 1){
        for (int i = 0; i < n; i++)
        scanf("%d", &R[i]);

        int maxv = -2000000000;
        int minv = R[0];

        for (int i = 1; i < n; i++) {
            maxv = max(maxv, R[i] - minv);
            minv = min(minv, R[i]);
        }
        
        printf("%d\n", maxv);
        }

    return 0;
}