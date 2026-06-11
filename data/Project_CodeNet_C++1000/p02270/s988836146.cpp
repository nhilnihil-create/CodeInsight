//allocation
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int n, k,maxp, w[999999], sum[999999];
int main(){
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++){
        scanf("%d", &w[i]);
        sum[i] = sum[i-1]+w[i];
        maxp = max(maxp, w[i]);
    }
    maxp = max(maxp, sum[n]/k);
    while(true){
        int now = maxp;
        int *nowpos = sum;
        for(int i = 1; i <= k; i++){
            //search
            nowpos = upper_bound(nowpos, sum+n+1, now);
            now = *(nowpos-1)+maxp;
        }
        //end
        if(nowpos == sum+n+1) break;
        else maxp++;
    }
    printf("%d\n", maxp);

}

