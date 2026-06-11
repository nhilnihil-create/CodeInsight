#include<cstdio>
using namespace std;

int n;
const int maxn = 505;
int log2[maxn];
 int lowbit(int x) {return x&(-x);}
signed main(){
    scanf("%d", &n);
    log2[1] = 0; log2[2] = 1;
    for(int i = 4; i <= 500; i++) {
        log2[i] = log2[i/2] + 1;
    }
    for(int i = 1; i < n; i++) {
        for(int j = i+1; j <= n; j++) {
            printf("%d ", log2[lowbit(i ^ j)] + 1);
        }
        puts("");
    }
    return 0;
}