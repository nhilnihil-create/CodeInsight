#include<bits/stdc++.h>

#define rep(i,N) for(int i=0;i<N;i++)
#define rep2(i,N) for(int i=1;i<=N;i++)
using namespace std;
long long  INF=1e18;
long long mod=1e9+7;

//status unsolved

int main(){
    long long n,m,v,p;
    cin>>n>>m>>v>>p;

    vector<long long> a(n);
    rep(i,n)cin>>a[i];

    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    long long sum[n+1];
    sum[0]=0;
    rep(i,n)sum[i+1]=sum[i]+a[i];

    long long border=a[p-1];
    long long ans=0;
    for(long long i=0;i<n;i++){
        if(a[i]>=border){
            ans++;
        }
        else{
            long long  L=n-(i+1);
            long long voter=v-(L+1);
            long long res=m*voter;
            if(voter<=0 && a[i]+m>=border){
                ans++;
            }
            else if(voter<p && a[i]+m>=border){
                ans++;
            }
            else if(voter>=p){
                voter-=(p-1);
                res=voter*m;
                //残りのresを分配する
                long long new_border=a[i]+m;
                if(a[p-1]>new_border){
                    continue;
                }
                else{
                long long mergin=new_border*(i-(p-1))-(sum[i]-sum[p-1]);
                res-=mergin;
                }
                /*
                for(int k=p-1;k<i;k++){
                    if(new_border<a[k])break;
                    res-=new_border-a[k];
                }*/
                if(res<=0)ans++;
            }
        }
    }

    cout<<ans<<endl;
    return 0;

}
/*


*/
