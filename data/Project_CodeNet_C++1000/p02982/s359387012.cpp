#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
int main()
{
    int n,d,ans=0;
    cin>>n>>d;
    vector<vector<int>> a(n,vector<int>(d));
    rep(i,n) rep(j,d) cin>>a[i][j];
    rep(n1,n){
        for(int n2=n1+1;n2<n;n2++){
            ll sum=0;
            rep(d1,d){
                sum+=(a[n1][d1]-a[n2][d1])*(a[n1][d1]-a[n2][d1]);
            }
            bool r=false;
            for(int i=0;i<=sum;i++){
                if(i*i==sum){
                    r=true;
                    break;
                }
            }
            if(r==true) ans++;
        }
    }
    cout<<ans;
}