#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    int n,mini=0,maxi=102; cin>>n;
    vector<int> x(n);
    rep(i,n){
        cin>>x[i];
        mini=min(mini,x[i]);
        maxi=max(maxi,x[i]);
    }
    int ans=INFINITY;
    for(int i=mini;i<=maxi;i++){
        int c=0;
        rep(j,n) c+=(x[j]-i)*(x[j]-i);
        ans=min(ans,c);
    }
    cout<<ans<<endl;
}