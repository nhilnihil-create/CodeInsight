#include <bits/stdc++.h>
using namespace std;

int H[305];
int sortedH[305];

long long memo[305][305];

// j: k left unclaimed
long long dp(int i, int j){
    if(i == 0){
        return 0;
    }else if(i == 1){
        return H[1];
    }else if(memo[i][j] != -1){
        return memo[i][j];
    }else{
        long long ans = max(H[i]-H[i-1], 0)+dp(i-1, j);
        int min1 = 2147483647;
        // pivot at indx i
        int jPen = 0;
        // x is beginning of continuous strip of at least min1
        // 9 14 5 8 9
        for(int x = i-1; x >= max(i-j, 1); x --){
            jPen ++;
            if(jPen > j){break;}
            min1 = min(min1, H[x]);
            if(1){
                ans = min(ans, max(H[i]-H[x-1], 0) + dp(x-1, j-jPen));
            }
        }
        //printf("%d %d %lld\n", i, j, ans);
        return memo[i][j] = ans;
    }
}

int main(){
    int N, K;
    scanf("%d%d", &N, &K);

    sortedH[0] = H[0] = 0;
    for(int i = 1; i <= N; i ++){
        scanf("%d", &H[i]);
        sortedH[i] = H[i];
    }
    memset(memo, -1, sizeof(memo));
    printf("%lld", dp(N+1, K));
    return 0;
}
