#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
int L[2001];

int main(void){
    int N, ab, cIdx, ans=0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &L[i]);
    sort(L, L+N);
    for (int i = 0; i < N-2; i++) {
        for (int j = i + 1; j < N-1; j++) {
            ab = L[i] + L[j]-1;
            //cIdx = int(upper_bound(L, L+N, ab)-L);
            for (int k = j + 1; k < N; k++) {
                if (L[i]+L[j] > L[k] && L[i] + L[k] > L[j] && L[j] + L[k] > L[i]) ans++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
