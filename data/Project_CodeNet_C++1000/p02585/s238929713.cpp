#include<bits/stdc++.h>
using namespace std;
const long long inf=1000000000000000000;
int main(){
    #define int long long
    int n,K;
    cin>>n>>K;
    int p[n],c[n];
    for(int i=0;i<n;i++){
        cin>>p[i];
        p[i]--;
    }
    for(int i=0;i<n;i++)cin>>c[i];
    int ans=-inf;
    for(int i=0;i<n;i++){
        int v=i,k=K,score=0,maxscore=-inf,syuki=1,syuki_score,start,cont=0;
        int visit[n]={};
        while(visit[v]==0 && k>0){
            visit[v]=1;
            v=p[v];
            score+=c[v];
            maxscore=max(maxscore,score);
            k--;
        }
        ans=max(ans,maxscore);
        if(k==0)continue;
        start=v;
        syuki_score=c[v];
        while(p[v]!=start){
            v=p[v];
            syuki_score+=c[v];
            syuki++;
        }
        if(syuki_score>0)score+=syuki_score*(k/syuki-1);
        k=k%syuki+syuki;
        maxscore=score;
        for(int j=0;j<k;j++){
            v=p[v];
            score+=c[v];
            maxscore=max(maxscore,score);
        }
        ans=max(ans,maxscore);
    }
    cout<<ans<<endl;
    return 0;
}
