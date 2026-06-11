#include <cstdio>
#include <algorithm>
using namespace std;

#define ll long long int
#define mx 200005
ll A[mx],B[mx];

int bin_search(int time, int m){
    if(B[0]>time) return 0;
    if(B[m-1]<=time) return m;

    int l=0,r=m-1;
    while(r-l>1){
        int mid=(l+r)/2;
        if(B[mid]<=time) l=mid;
        else r=mid;
    }
    return r;
}

int main(){
    int n,m,time;
    scanf("%d %d %d",&n,&m,&time);
    for(int i=0;i<n;i++) {scanf("%lld",&A[i]); if(i>0) A[i]+=A[i-1];};
    for(int i=0;i<m;i++) {scanf("%lld",&B[i]); if(i>0) B[i]+=B[i-1];};

    int ans=bin_search(time,m);

    for(int i=0;i<n;i++) if(A[i]<=time){
        ans=max(ans,i+1+bin_search(time-A[i],m));
    }

    printf("%d\n",ans);
}
