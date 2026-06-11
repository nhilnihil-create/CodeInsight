#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int>pli;

const int N=10;
const int M=55;
ll cnt[N][M];
int v[N][M];

void init(){
    for(int i=0;i<N;i++){
        v[i][0]=i,cnt[i][0]=0;
        for(int j=1;j<M;j++){
            cnt[i][j]=2*cnt[i][j-1]+1;
            v[i][j]=2*v[i][j-1];
            if(v[i][j]>=10) v[i][j]-=9,cnt[i][j]++;
        }
    }
}

void calAns(pli& ans,int num,ll len){
    ll& curcnt=ans.first;
    int& curv=ans.second;
    for(int i=0;i<M;i++){
        if((len>>i)&1){
            curcnt+=cnt[num][i]+1;
            curv+=v[num][i];
            if(curv>=10) curv-=9,curcnt++;
        }
    }
}

void solve(){
    init();
    pli ans=pli(0LL,0);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int d;
        ll c;
        scanf("%d%lld",&d,&c);
        calAns(ans,d,c);
    }
    printf("%lld\n",ans.first-1);
}

int main(){

    solve();
    return 0;
}