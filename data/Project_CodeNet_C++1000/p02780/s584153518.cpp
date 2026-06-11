#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    rep(i,n)cin>>a[i];
    double calc=0,ans=0;
    rep(i,k){
        calc+=(double)a[i]/2+0.5;
    }
    ans=max(ans,calc);
    rep(i,n-k){
        calc-=(double)a[i]/2+0.5;
        calc+=(double)a[i+k]/2+0.5;
        ans=max(ans,calc);
    }
    printf("%.10f\n",ans);
    return 0;
}