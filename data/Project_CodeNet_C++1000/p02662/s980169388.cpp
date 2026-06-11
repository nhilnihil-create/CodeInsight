#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
typedef signed long long ll;
#define FOR(i,to) for(i=0;i<(to);i++)

int dp[3000+10][3000+10];
const ll mod=998244353;
int main() {
	int i,j,k,l,r,x,y; string s;

    int N;
    int S;
    cin >> N;
    cin >> S;

    int sr[N];
    FOR(i,N) cin>>sr[i];

    dp[0][0]=1;

    for(i=1;i<=N;i++){
        for(j=0;j<=S;j++){
            (dp[i][j]=dp[i-1][j]*2)%=mod;
            if(j>=sr[i-1]){
                y=j-sr[i-1];
                (dp[i][j]+=dp[i-1][y])%=mod;
            }
        }
    }
    std::cout << dp[N][S];
}

