#include<bits/stdc++.h>
using namespace std;

const long long MOD=1000000007;
long long counta[300000][60][2];

int main(){
    //input
    long long N;
    cin >> N;
    long long A[N];
    long long i,j,k;
    for(i=0; i<N; i++){
        cin >> A[i];
    }

    //calc
    long long nibeki[60];
    nibeki[0]=1;
    for(i=1; i<60; i++){
        nibeki[i]=2*nibeki[i-1];
        nibeki[i]%=MOD;
    }
    for(i=0; i<300000; i++){
        for(j=0; j<60; j++){
            for(k=0; k<2; k++){
                counta[i][j][k]=0;
            }
        }
    }
    for(i=0; i<N-1; i++){
        for(j=0; j<60; j++){
            if((A[i]&((1LL)<<j))>0){
                counta[i+1][j][1]++;
            }else{
                counta[i+1][j][0]++;
            }
        }
    }
    for(i=0; i<N-1; i++){
        for(j=0; j<60; j++){
            for(k=0; k<2; k++){
                counta[i+1][j][k]+=counta[i][j][k];
                counta[i+1][j][k]%=MOD;
            }
        }
    }
    long long ans=0;
    for(i=1; i<N; i++){
        for(j=0; j<60; j++){
            if((A[i]&((1LL)<<j))>0){
                ans+=counta[i][j][0]*nibeki[j];
                ans%=MOD;
            }else{
                ans+=counta[i][j][1]*nibeki[j];
                ans%=MOD;
            }
        }
    }

    //output
    cout << ans << endl;
    system("pause");
    return 0;
}