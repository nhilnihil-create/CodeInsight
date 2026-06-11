#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mid ((l+r)>>1)
const int M=3e5+20,P=1e9+7;
struct Task{
    LL n,m,v,p,a[M];
    LL sum[M];
    void run(){
        init();
        sort(a+1,a+n+1);
        for(int i=1;i<=n;++i){
        	sum[i]=sum[i-1]+a[i];
		} 
        LL ans=n-p;
        while(ans>=1){
            if(a[ans]+m<a[n-p+1]){
            	break;
			}   
            if(1LL*(ans+p-1)*m+1LL*(n-p+1-(ans+1)+1)*(a[ans]+m)-(sum[n-p+1]-sum[ans])>=1LL*v*m){
            	--ans;
			}   
            else{
            	break;
			}
        }
        printf("%lld\n",n-ans);
    }
    void init(){
        scanf("%lld%lld%lld%lld",&n,&m,&v,&p);
        for(int i=1;i<=n;++i){
        	scanf("%lld",&a[i]);
		}
    }
}t;
int main(){
    t.run();
    return 0;
}