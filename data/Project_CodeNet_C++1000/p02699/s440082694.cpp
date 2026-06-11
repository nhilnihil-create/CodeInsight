#include <bits/stdc++.h>
 
using namespace std;
#define repr(i,a,b) for (int i=a; i<b; i++)
#define rep(i,n) for (int i=0; i<  n; i++)
 
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
 
const long long INF = 1LL << 60;
 
bool dp[100100];
 
 
int main () {
    int S , W;
    scanf("%d%d",&S,&W);

    if(S <= W)printf("%s\n","unsafe");
    else printf("%s\n","safe");

    return 0;



}