#include<iostream>
using namespace std;

long long MOD=1000000007;

int main(){
    //input
    long long N,M;
    cin >> N >> M;
    long long S[N+1], T[M+1];
    long long i,j;
    for(i=1; i<=N; i++){
        cin >> S[i];
    }
    for(j=1; j<=M; j++){
        cin >> T[j];
    }

    //calc
    long long sum[N+1][M+1];
    for(i=0; i<=N; i++){
        sum[i][0]=1;
    }
    for(j=0; j<=M; j++){
        sum[0][j]=1;
    }
    for(i=1; i<=N; i++){
        for(j=1; j<=M; j++){
            if(S[i]==T[j]){
                sum[i][j]=sum[i-1][j]+sum[i][j-1];
                sum[i][j]%=MOD;
            }else{
                sum[i][j]=sum[i-1][j]+sum[i][j-1]+MOD-sum[i-1][j-1];
                sum[i][j]%=MOD;
            }      
        }
    }

    //answer
    cout << sum[N][M] << endl;
    system("pause");
    return 0;
}