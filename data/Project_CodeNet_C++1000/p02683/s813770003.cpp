#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int N, M, X;
    cin >> N >> M >> X;
    int C[N], A[N][M];
    rep(i, N){
        cin >> C[i];
        rep(j, M) cin >> A[i][j];
    }

    int S[N]={0};
    int score[M]={0};
    int ans=-1;
    while(true){
        int sum=0;
        rep(i, N) if(S[i]==2){ S[i]=0; S[i+1]++;}
        
        rep(i, N){
            if(S[i]==1){
                rep(j, M) score[j]+=A[i][j];
                sum+=C[i];
            }
        }

        int flag=0;
        rep(i, M) if(score[i]<X) flag=1;
        if(flag==0) if(ans>sum || ans==-1) ans=sum;

        int end=1;
        rep(i, N) if(S[i]==0) end=0;
        if(end==1) break;
        rep(i, M) score[i]=0;
        S[0]=S[0]+1;
    }
    cout << ans << endl;
    return 0;
}
/*
12 1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
*/