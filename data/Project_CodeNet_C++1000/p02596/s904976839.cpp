#include <bits/stdc++.h>
using namespace std;
int main(void){
    int k; cin >> k;
    int a[1000001];
    a[1] = 7%k;
    for (int i = 2; i <= k; ++i){a[i] = (a[i-1]*10 + 7)%k;}
    for(int i=1;i<=k;i++){
        if(a[i]==0){
            printf("%d\n",i);
            return 0;
        }
    }
    printf("-1\n");
}