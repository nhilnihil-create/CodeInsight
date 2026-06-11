#include<cstdio>
long long a[100005];
long long upper[100005], lower[100005];
long long power[100005];
long long count[100005]; // inner node

long long min(long long a,long long b){ return a>b?b:a; }

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0; i <= n; i++) scanf("%lld",&a[i]);
    upper[n] = 0;
    for(int i = n-1; i >= 0; i--){
        upper[i] = upper[i+1]+a[i+1];
    }
    count[0] = 1-a[0];
    int ok = 1; long long ans = 1;
    if(count[0]>upper[0] || a[0]>1) ok = 0; 
    for(int i = 1; i <= n; i++){
        if(2*count[i-1]<a[i]){
            ok = 0;
            break;
        }
        else{ 
            count[i] = min(upper[i],2*count[i-1]-a[i]);
            ans += count[i]+a[i];
        }
    }
    if(!ok) printf("-1\n");
    else printf("%lld\n",ans);
    return 0;
}
