#include<iostream>
#include<cstdio>
using namespace std;

int input[100],N,M;
int situ[2] = {-1,1};
long long memo[200][21];

long long solve(int n,int dep){
    long long ans=0;
    if(n>20 || n<0) return 0;
    if(dep==N-1){
        //printf("%d %d\n",N,M);
        if(n==M) return 1;
        else return 0;
    }
    if(memo[dep][n] != -1) return memo[dep][n];

    for(int i=0;i<2;i++){
        ans += solve(n+input[dep]*situ[i],dep+1);
    }
    memo[dep][n]=ans;
    return ans;
}

int main(){
    for(int i=0;i<200;i++)for(int j=0;j<=20;j++) memo[i][j]=-1;
    cin >> N;
    for(int i=0;i<N-1;i++){
        cin >> input[i];
    }
    cin >> M;
    /*for(int i=0;i<N-1;i++) printf("%d ",input[i]);
    puts("");*/
    printf("%lld\n",solve(input[0],1));
    return 0;
}