#include <bits/stdc++.h>
#define rep(i, n)	for(int i=0;i<(int)(n);i++)
using namespace std;
using ll=long long;

int main(){
    int n;
    cin>>n;
    int x[10],y[10];
    rep(i, n) cin>>x[i]>>y[i];
    double ans=0;
    int sum=0;
    int pro=1;
    rep(i,n){
        sum+=i;
        pro*=i+1;
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            ans+=sqrt(pow((x[j]-x[i]),2)+(pow((y[j]-y[i]),2)));
        }
    }
    ans*=pro*(n-1)/sum;
    while(n>0) {
        ans/=n;
        n--;
    }
    cout<<fixed<<setprecision(12)<<ans<<endl;
}