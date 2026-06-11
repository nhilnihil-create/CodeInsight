#include <bits/stdc++.h>
using namespace std;

int main(){
    char a[1001], b[1001];
    scanf("%s%s", a, b);
    int aL = strlen(a), bL = strlen(b);
    int res = aL;
    for(int i = 0; i <= aL - bL; i++){
        int dif = 0;
        for(int j = 0; j < bL; j++){
            if(b[j] != a[i + j])
                dif++;
        }
        res = min(res, dif);
    }
    printf("%d\n", res);
    return 0;
}
