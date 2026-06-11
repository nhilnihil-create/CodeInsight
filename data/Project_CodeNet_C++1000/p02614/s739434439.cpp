#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

#define FOR(i,N) for(int i=0;i<N;i++)

int main(){
    long long H,W,Q,M,X,K,N,x,cnt=0,min=-1,max=0,sum=0;
    cin >> H >> W >> K;
    vector<vector<char>>c(H,vector<char>(W));
    FOR(i,H)FOR(j,W)cin >> c[i][j];

    FOR(is,1<<H)FOR(js,1<<W){
        int n=0;
        FOR(i,H)FOR(j,W){
            if(is & 1<<i)continue;
            if(js & 1<<j)continue;
            if(c[i][j]=='#')n++;
        }
        if(n==K)cnt++;
    }
    cout <<cnt;
}
