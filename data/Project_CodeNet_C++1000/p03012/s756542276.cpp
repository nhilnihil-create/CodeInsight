#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
int main()
{
    int n,ans=1e9;
    cin>>n;
    vector<int> w(n);
    rep(i,n) cin>>w[i];
    rep(i,n){
        int sum1=0,sum2=0;
        rep(j,n){
            if(j<=i) sum1+=w[j];
            else sum2+=w[j];
        }
        ans=min(ans,abs(sum1-sum2));
    }
    cout<<ans;
}