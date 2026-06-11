#include <cstdio>
#include <algorithm>

using namespace std;
int a[200000];

int main(){
    int n, k, t;
    scanf("%d%d", &n, &t);
    int i;
    int l = 0, r = 0, m;
    for(i = 0; i < n; ++i){
        scanf("%d", &a[i]);
        if(a[i] > r)
            r = a[i];
    }
    sort(a, a + n);
    while(true){
        m = (l + r) >> 1;
        if(m == 0){
            printf("1\n");
            return 0;
        }
        k = t;
        for(i = n - 1; i >= 0; --i)
            if(a[i] <= m)
                break;
            else{
                k -= (a[i] - 1) / m;
                if(k < 0)
                    break;
            }
        if(k >= 0)
            r = m;
        else
            l = m;
        if(r == l + 1){
            printf("%d\n", r);
            break;
        }
    }
    return 0;
}
