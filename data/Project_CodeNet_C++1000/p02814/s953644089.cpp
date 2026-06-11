#include<bits/stdc++.h>

#define rep(i,N) for(int i=0;i<N;i++)
#define rep2(i,N) for(int i=1;i<=N;i++)
using namespace std;
long long  INF=1e18;
long long mod=1e9+7;

//status unsolved
long long gcd(long long x, long long y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

long long lcm(long long a,long long b){
    return ((a*b)/(gcd(a,b)));
}

int main(){
    

    long long n,m;
    cin>>n>>m;

    long long a[n];
    long long ans=0;
    int cnt=0;
    rep(i,n){
        cin>>a[i];
        
        if(a[i]%2!=0){
            cout<<ans<<endl;
            return 0;
        }
        else{
            a[i]/=2;
            int tmp=0;
            long long A=a[i];
            while(A%2==0){
                A/=2;
                tmp++;
            }
            if(cnt!=tmp && cnt>0){
                cout<<ans<<endl;
                return 0;
            }
            else{
                cnt=tmp;
            }
        }
        
    }
    long long LCM=1;
    rep(i,n){
        LCM=lcm(LCM,a[i]);
    }
    //cout<<LCM<<endl;
    ans=floor((long double)m/LCM);
    ans=ceil((long double)ans/2);

    cout<<ans<<endl;

    return 0;

}
/*


*/
