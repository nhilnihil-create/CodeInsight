#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<map>
#define all(x) (x).begin(),(x).end()
#define print(x) cout << (x) << endl
typedef long long ll;
const ll MOD = 1000000007;
 
using namespace std;

int main(){
    int N, M;   cin >> N >> M;
    vector<int> dp(N+1), a(N,0);
    for(int i=0; i<M; i++){
        int v;  cin >> v;
        a[v] = 1;
    }
    dp[0] = 1;
    for(int i=1; i<=N; i++){
        if(a[i] == 1)   dp[i] = 0;
        else{
            if(i > 1)dp[i] = dp[i-1] + dp[i-2];
            else    dp[i] = dp[i-1];
            dp[i] %= MOD;
        }
    }
    cout << (dp[N]+MOD)%MOD << endl;
    return 0;
}