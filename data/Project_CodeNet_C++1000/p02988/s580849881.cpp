#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, res = 0;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(int i = 0; i < n - 1; i++){
        if(a[i] > a[i + 1] && a[i + 1] > a[i + 2] && i + 2 < n){
            res++;
        }
        if(a[i] < a[i + 1] && a[i + 1] < a[i + 2] && i + 2 < n){
            res++;
        }
    }
    printf("%d", res);
    return 0;
}
