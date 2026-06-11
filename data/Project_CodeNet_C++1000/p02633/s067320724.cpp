#include <bits/stdc++.h>
#define siz (int)3e5 + 7
using namespace std;

int n;
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        if((360 * i) % n == 0){
            printf("%d", (360 * i) / n);
            break;
        }
    }
}
