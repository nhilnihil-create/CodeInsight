#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;

int n;
int m;
int h[N];
int ans[N];

int main(){
    scanf("%d%d" , &n , &m);
    for(int i = 1; i <= n; i++){
        scanf("%d" , &h[i]);
    }
    for(int j = 1; j <= m; j++){
        int a, b;
        scanf("%d%d" , &a , &b);
        ans[a] = max(ans[a] , h[b]);
        ans[b] = max(ans[b] , h[a]);
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(ans[i] < h[i]){
            cnt++;
        }
    }
    printf("%d\n" , cnt);
}
