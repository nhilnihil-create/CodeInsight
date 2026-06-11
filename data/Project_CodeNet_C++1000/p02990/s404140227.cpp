#include<bits/stdc++.h>
using namespace std;

#define Q int t; scanf("%d", &t); for(int q=1; q<=t; q++)
typedef long long int lli;
typedef pair<lli, lli> pi;

#define N 2005

lli ncr[N][N], mod = 1000000007;

void getcom()
{
    for(int i=0; i<N; i++){
        ncr[i][0] = ncr[i][i] = 1LL;
        ncr[i][1] = i;
    }
    for(int i=3; i<N; i++){
        for(int j=2; j<i; j++){
            ncr[i][j] = (ncr[i-1][j-1]+ncr[i-1][j]) % mod;
        }
    }
}

int main()
{
    getcom();
    int n, k;
    cin >> n >> k;

    int x = n-k;
    for(int i=1; i<=k; i++){
        if(i == 1){
            cout << x+1 << "\n";
        }
        else{
            cout << ncr[k-1][i-1]*ncr[x+1][i]%mod << "\n";
        }
    }

    return 0;
}
