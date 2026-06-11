#include <iostream>
#include <vector>
//#include <string>
#include <algorithm>
//#include <math.h>
//#include <queue>
//#include <stack>
//#include <iomanip>

// sometimes used
//#include <set>
//#include <map>
//#include <numeric>
//#include <list>
//#include <deque>
//#include <unordered_map>

typedef long long LL;
//typedef long double LD;
using namespace std;
 
//#define MOD 1000000007
//#define MAX 100100
#define NIL -1
//#define INFTY 1000000000000000000

LL lpow(LL x, LL n){
    LL ans = 1;
    while(n>0){
        if((n&1)==1){
            ans = (ans * x);
        }
        x = x * x;
        n >>= 1;
    }
    return ans;
}
int main(){
    LL n;
    LL m;
    cin >> n >> m;
    LL num=lpow(2,n);
    vector<LL> a(m);
    LL b;
    vector<LL> c(m);
    LL tmp_c;
    for(LL i=0; i<m; i++){
        cin >> a[i] >> b;
        LL tmp=0;
        for(LL j=0; j<b; j++){
            cin >> tmp_c;
            tmp_c--;
            tmp+=lpow(2, tmp_c);
        }
        c[i]=tmp;
    }

    vector<vector<LL>> dp(m+1, vector<LL>(num, NIL));
    for(LL i=0; i<=m; i++){
        dp[i][0]=0;
    }
    for(LL i=1; i<=m; i++){
        for(LL j=0; j<num; j++){
            if(dp[i-1][j]==NIL){
                continue;
            }
            if(dp[i][j]==NIL){
                dp[i][j]=dp[i-1][j];
            }else{
                dp[i][j]=min(dp[i][j], dp[i-1][j]);
            }
            LL tmp=c[i-1];
            LL tmp_j=j;
            LL tmp_dist=0;
            for(LL k=0; k<n; k++){
                if(tmp%2==1 || tmp_j%2==1){
                    tmp_dist=tmp_dist+lpow(2,k);
                }
                tmp/=2;
                tmp_j/=2;
            }
            if(dp[i][tmp_dist]==NIL){
                dp[i][tmp_dist]=dp[i-1][j]+a[i-1];
            }else{
                dp[i][tmp_dist]=min(dp[i][tmp_dist], dp[i-1][j]+a[i-1]);
            }
            //cout << i << " " << j << " " << tmp_dist << " " << dp[i][tmp_dist] << endl;
        }
    }

    cout << dp[m][num-1] << endl;

    return 0;
}
