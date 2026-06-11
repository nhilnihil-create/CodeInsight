#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+5;

int n , k;
bool yes[N];

int main(){
    scanf("%d%d" , &n , &k);
    for(int i = 1; i <= k; i++){
        int d;
        scanf("%d" , &d);
        for(int j = 1; j <= d; j++){
            int x;
            scanf("%d" , &x);
            yes[x] = 1;
        }
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        cnt += !yes[i];
    }
    printf("%d\n" , cnt);
}
