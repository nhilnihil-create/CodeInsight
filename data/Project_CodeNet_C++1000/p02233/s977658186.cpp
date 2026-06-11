#include <bits/stdc++.h>
#include<math.h>
#include<algorithm> 
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18

int dp [50] ;
int fib(int x){
    if(x == 1 || x == 0){
        return 1 ;
    }
    if(dp[x]>0){
        return dp[x] ;
    }
    dp[x] = fib(x-1) + fib(x-2) ;
    return fib(x-1) + fib(x-2) ;
}
int main() {
    int n ;
    cin >> n ;
    int ans = fib(n) ;
    cout << ans << endl ; 
} 
