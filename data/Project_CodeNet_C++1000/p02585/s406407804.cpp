#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,k,loopnum=0,num,next,mg[1000];
    long long int spl[1000],ans;
    cin>>n>>k;
    int p[n],c[n],group[n];
    for(int i=0;i<n;i++)cin>>p[i];
    for(int i=0;i<n;i++)cin>>c[i];
    for(int i=0;i<n;i++)group[i]=-1;
    for(int i=0;i<n;i++){
        if(group[i]==-1){
            group[i]=loopnum;
            spl[loopnum]=0;
            mg[loopnum]=1;
            next=i;
            while(1){
                next=p[next]-1;
                spl[loopnum]+=c[next];
                if(group[next]==-1){
                    mg[loopnum]++;
                    group[next]=loopnum;
                }
                else break;
            }
            loopnum++;
        }
    }
    long long int maxinloop[loopnum];
    for(int i=0;i<loopnum;i++){
        long long int maxl=LONG_LONG_MIN,maxs=LONG_LONG_MIN,count=0;
        for(int j=0;j<mg[i];j++){
            count=0;
            next=-1;
            for(int l=0;l<=j;l++){
                while(1){
                    next++;
                    if(group[next]==i)break;
                }
            }
            for(int l=0;l<mg[i]-1;l++){
                next=p[next]-1;
                count+=c[next];
                if(l<k%mg[i]){if(maxl<count)maxl=count;}
                else if(maxs<count)maxs=count;
            }
        }
        if(mg[i]>k)maxinloop[i]=maxl;
        else if(spl[i]<=0)maxinloop[i]=max(maxl,maxs);
        else{
            long long int a=k/mg[i];
            maxinloop[i]=max(max(spl[i]*a+maxl,spl[i]*a),spl[i]*(a-1)+maxs);
        }
    }
    ans=maxinloop[0];
    for(int i=1;i<loopnum;i++){
        if(ans<maxinloop[i])ans=maxinloop[i];
    }
    cout<<ans<<endl;
    return 0;
}