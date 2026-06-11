#include<bits/stdc++.h>
using namespace std;

const int INF=1001001001;
int N;
int dp[100010];

int main(){
    cin>>N;
    fill_n(dp,N+3,INF);
    dp[0]=-1;

    for(int i=0;i<N;i++){
        int A;cin>>A;
        *lower_bound(dp,dp+N+3,A)=A;
    }

    cout<<lower_bound(dp,dp+N+3,INF)-dp-1<<endl;
}