#include<bits/stdc++.h>
using namespace std;

long long n;

long long a[1000000+50],b[1000000+50];

long long pre(long long x){
    return (x-1+n)%n;
}
long long nxt(long long x){
    return (x+1)%n;
}
int main(){
    ios::sync_with_stdio(false);
    
    cin>>n;
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    priority_queue <pair <long long,long long> > pq;
    for(long long i=0;i<n;i++){
        cin>>b[i];
        if(b[i]>a[i])
        pq.push({b[i],i});
    }
    long long ans=0;
    bool poss=true;
    while(pq.empty()==0){
        auto frnt=pq.top();
        pq.pop();
        long long cur=frnt.second;
        long long pre=(cur-1+n)%n;
        long long nxt=(cur+1)%n;
        if(b[pre]+b[nxt]<b[cur]&&b[cur]>a[cur]){
            long long cnt=(b[cur]-a[cur])/(b[pre]+b[nxt]);
            ans+=cnt;
            b[cur]-=cnt*(b[pre]+b[nxt]);
            
            frnt.first=b[cur];

            if(cnt==0){
                poss=false;
                break;
            }

            if(b[cur]>a[cur]){
                pq.push(frnt);
            }

        }
        else{
            poss=false;
            break;
        }
        
    }

    // for(long long i=0;i<n;i++){
    //     if(a[i]!=b[i])poss=false;
    // }

    if(!poss){
        cout<<-1;
    }
    else{

        cout<<ans;
    }
    // cout<<"\n";
    // for(long long i=0;i<n;i++){
    //     cout<<b[i]<<" ";
    // }


    return 0;
}