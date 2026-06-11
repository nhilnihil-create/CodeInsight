#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

 
int main(){
    int n,k;
    cin>>n>>k;
    vector<double> p(n);
    rep(i,n){
        cin>>p[i];
        p[i]=(p[i]+1)/2;
    }
    vector<double> s(n+1,0);
    rep(i,n) s[i+1]=s[i]+p[i];

    double ans=0;
    for(int i=k;i<n+1;i++){
        ans=max(ans,s[i]-s[i-k]);
    }

    cout<<fixed<<setprecision(10)<<ans<<endl;
}