#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <bitset>     //UWAGA - w czasie kompilacji musi byc znany rozmiar wektora - nie mozna go zmienic
#include <cassert>
#include <iomanip>        //do setprecision
#include <ctime>
#include <complex>
using namespace std;

#define FOR(i,b,e) for(int i=(b);i<(e);++i)
#define FORQ(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b)-1;i>=(e);--i)
#define REP(x, n) for(int x = 0; x < (n); ++x)

#define ST first
#define ND second
#define PB push_back
#define PF push_front
#define MP make_pair
#define LL long long
#define ULL unsigned LL
#define LD long double
#define pii pair<int,int>
#define pll pair<LL,LL>
#define vi vector<int>
#define vl vector<LL>
#define vii vector<vi>
#define vll vector<vl>

const double pi = 3.14159265358979323846264;
const int mod=1000000007;
const LL lm=1LL*mod*mod;

int main(){
    int n,k;
    cin>>n>>k;
    vl h(n+1,0);
    FOR(i,0,n){
        cin>>h[i+1];
    }
    vll dp(n+2,vl(k+2,lm));
    dp[0][0]=0;
    FOR(i,0,n+1){
        FOR(j,0,k+1){
            LL nw=dp[i][j];
            FOR(p,0,k-j+1){
                if(p+1+i>n+1)break;
                if(p+1+i==n+1){
                    dp[p+1+i][j+p]=min(dp[p+1+i][j+p],nw);
                }else{
                    dp[p+1+i][j+p]=min(dp[p+1+i][j+p],nw+max(0LL,h[p+1+i]-h[i]));
                }
            }
        }
    }
    LL ans=lm;
    FOR(i,0,k+1){
        ans=min(ans,dp[n+1][i]);
    }
    cout<<ans;
    



}
