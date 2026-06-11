/// However long the night,
///     The dawn will break
/// ICPC next year

#include<bits/stdc++.h>
using namespace std ;
const int N = 2e3+5 ,mod = 1e9+7 ;

int n ,m ,a[N] ,b[N] ,mem[N][N] ;

int solve(int i,int j){
    if(i==n || j==m) return 1;
    int&ret = mem[i][j];
    if(~ret) return ret;
    ret = (solve(i+1,j) + solve(i,j+1) - solve(i+1,j+1))%mod;
    ret = (ret + mod)%mod;
    if(a[i]==b[j]) ret = (ret + solve(i+1,j+1))%mod;
    return ret;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i) scanf("%d",a+i);
    for(int i=0;i<m;++i) scanf("%d",b+i);
    memset(mem,-1,sizeof mem);
    cout << solve(0,0);
    return 0;
}
