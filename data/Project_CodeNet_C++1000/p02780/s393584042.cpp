#include <bits/stdc++.h>
#define rep(i, n)	for(int i=0;i<(int)(n);i++)
using namespace std;
using ll=long long;

int main(){
    int n,k;
    cin>>n>>k;
    int p[200010];
    rep(i, n){
        cin>>p[i];
    }
    int sum=0;
    rep(i,k) sum+=p[i];
    int ans=sum;
    for(int i=1;i<=n-k;i++){
        sum-=p[i-1];
        sum+=p[i+k-1];
        ans=max(ans,sum);
    }
    double ANS=(double)(ans+k)/2.0;
    cout<<fixed<<setprecision(12)<<ANS<<endl;
}