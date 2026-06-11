#include<iostream>
#include<set>
using namespace std;

long long MOD=1000000007;

int main(){
    //input
    long long N,M;
    cin >> N >> M;
    long long S[N+1], T[M+1];
    long long i,j;
    set<long long> appear;
    for(i=1; i<=N; i++){
        cin >> S[i];
        appear.insert(S[i]);
    }
    for(j=1; j<=M; j++){
        cin >> T[j];
        appear.insert(T[j]);
    }

    //calc
    long long kosu=0;
    long long rank[100001];
    set<long long>::iterator t;
    for(t=appear.begin(); t!=appear.end(); ++t){
        rank[*t]=kosu;
        kosu++;
    }
    long long rowsum[N+1][kosu];
    long long colsum[M+1][kosu];
    for(i=0; i<=N; i++){
        for(j=0; j<kosu; j++){
            rowsum[i][j]=0;
        }
    }
    for(i=0; i<=M; i++){
        for(j=0; j<kosu; j++){
            colsum[i][j]=0;
        }
    }
    long long dp[N+1][M+1];
    for(i=0; i<=N; i++){
        dp[i][0]=1;
    }
    for(j=0; j<=M; j++){
        dp[0][j]=1;
    }
    for(i=1; i<=N; i++){
        for(j=1; j<=M; j++){
            dp[i][j]=dp[i-1][j-1]+(S[i]==T[j])*dp[i-1][j-1]+rowsum[i][rank[S[i]]]+colsum[j][rank[T[j]]];
            dp[i][j]%=MOD;
            rowsum[i][rank[T[j]]]+=dp[i-1][j-1];
            rowsum[i][rank[T[j]]]%=MOD;
            colsum[j][rank[S[i]]]+=dp[i-1][j-1];
            colsum[j][rank[S[i]]]%=MOD;
        }
    }

    //answer
    cout << dp[N][M] << endl;
    system("pause");
    return 0;
}