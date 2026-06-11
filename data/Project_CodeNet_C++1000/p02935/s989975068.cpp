#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long ;
int main()
{
    int n;
    double ans;
    cin>>n;
    vector<double> v(n);
    rep(i,n) cin>>v[i];
    sort(v.begin(),v.end());
    ans=v[0];
    rep(i,n-1){
        ans=(ans+v[i+1])/2;
    }
    printf("%.10f",ans);
}