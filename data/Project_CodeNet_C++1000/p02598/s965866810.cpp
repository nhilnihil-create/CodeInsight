#include<bits/stdc++.h>

#define rep(i,N) for(int i=0;i<N;i++)
#define rep2(i,N) for(int i=1;i<=N;i++)
using namespace std;
long long  INF=1e18;
long long mod=1e9+7;

//status unsolved

int main(){
    long long n,k;
    cin>>n>>k;

    long long a[n];
    rep(i,n)cin>>a[i];

    long long second[46];
    second[0]=1;
    long long sum[50];
    sum[0]=0;
    rep2(i,45){
        second[i]=second[i-1]*2;
        sum[i]=sum[i-1]+second[i-1];
        //cout<<sum[i]<<" ";
    }
    //cout<<endl;
    long long right=1e9;
    long long left=0;

    while(left+1<right){

        long long mid=(right+left)/2;

        long long cnt=0;
        //cout<<mid<<endl;
        rep(i,n){
            
            //if(a[i]<=mid)continue;

            cnt+=ceil(((double)a[i]/mid))-1;
            //cnt+=(a[i]+mid-1)/mid-1;
            
        }
        

        if(cnt>k){
            left=mid;
        }
        else{
            right=mid;
        }
    }
    //cout<<endl;

    cout<<right<<endl;
    return 0;

}
/*


*/
