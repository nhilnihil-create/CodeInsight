#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e2+10;
int a[maxn],b[maxn];
int n,k,ans=1;
void update(int x){
    int sum=0;
    for(int i=1;i<=n;i++){
        b[i]=a[i]%x;
        sum+=b[i];
    }
    sort(b+1,b+n+1,greater<int>());
    int sum1=sum;
    for(int i=1;i<=sum1/x;i++){
        sum-=b[i];
    }
    if(sum<=k)
        ans=max(ans,x);
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>k;
    ll sum=0;
    for(int i=1;i<=n;i++)cin>>a[i],sum+=a[i];
    for(int i=2;i*i<=sum;i++){
        if(sum%i==0){
            update(i);
            update(sum/i);
        }
    }
    update(sum);
    cout<<ans<<endl;
}
