#include<bits/stdc++.h>

#define rep(i,N) for(int i=0;i<N;i++)
#define rep2(i,N) for(int i=1;i<=N;i++)
using namespace std;
long long  INF=1e18;
long long mod=1e9+7;

//status unsolved
long long n,k;
int path[5010];
long long cost[5010];
vector<vector<long long>>sum(5010,vector<long long>(5010,0));


long long solve(int i){
    int move=1;
    int now=i;
    //1週の長さと累積和を求める。
    while(1){
        //sum[i].push_back(sum[i][move]+cost[path[now]]);
        sum[i][move]=sum[i][move-1]+cost[path[now]];
        move++;
        now=path[now];
        if(now==i){
            //cout<<"path_length="<<move-1<<endl;
            break;
        }
    }
    //L:=1週の長さ
    long long L=move-1;
    long long ret=0;
    
    int end=k%L;
    long long m=-INF;
    rep2(l,end){
        m=max(m,sum[i][l]);
    }
    if(end==0)m=0;
    long long M=-INF;
    //全区間での最大値
    rep2(l,L){
        M=max(M,sum[i][l]);
    }
    if(k>=L && sum[i][L]>=0){
        //ret+=(k/L)*sum[L];
        ret=max(m+(k/L)*sum[i][L],((k/L)-1)*sum[i][L]+M);
    }
    else if(k>=L && sum[i][L]<=0){
        ret=M;
    }
    else{
        ret=m;
    }

    // rep(l,L+1){
    //     cout<<sum[i][l]<<" ";
    // }
    // cout<<endl;
    // cout<<ret<<endl;
    return ret;

}
int main(){
    
    cin>>n>>k;
    rep2(i,n){
        cin>>path[i];
    }
    rep2(i,n){
        cin>>cost[i];
    }
    rep2(i,n)sum[i][0]=0;


    long long ans=-INF;
    rep2(i,n){
        ans=max(solve(i),ans);
    }
    cout<<ans<<endl;
    return 0;

}
/*


*/
