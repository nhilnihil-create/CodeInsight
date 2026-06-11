#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

#define FOR(i,N) for(int i=0;i<N;i++)

int main(){
    long long H,W,Q,M,X,K,N,x,cnt=0,min=-1,max=0,sum=0;
    cin >> N >> M >> X;
    vector<long>C(N),lv(M,0);
    vector<vector<long>>A(N,vector<long>(M));
    FOR(i,N){
        cin >> C[i];
        FOR(j,M){
            cin >> A[i][j];
        }
    }
    FOR(is,1<<N){
        long value=0;
        FOR(i,N){
            if(is & (1<<i)){
                FOR(k,M){
                    lv[k] += A[i][k];
                }
                value += C[i];
            }
        }
        FOR(i,M){
            if(lv[i]<X)break;
            if(i==M-1){
                if(min == -1 || (min > value))min=value;
            }
        }
        FOR(i,M)lv[i]=0;
    }
    cout << min;
}
