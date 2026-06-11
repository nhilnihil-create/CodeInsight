#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)
using ll = long long;
using namespace std;
int main(){
    int n;cin>>n;
    vector<int> l(n);
    rep(i,n)cin>>l[i];
    ll ans=0;
    sort(l.begin(),l.end());
    for(int i=0;i<n-1;i++)for(int j=i+1;j<n;j++){
        int x=l[i]+l[j];
        int a = lower_bound(l.begin(),l.end(),x)-l.begin();
        int b = j+1;
        ans+=a-b;
    }
    cout<<ans<<endl;
}