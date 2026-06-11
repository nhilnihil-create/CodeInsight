#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fori(i,a,b) for(int i=a;i<(int)(b);i++)
#define repi(i,n) fori(i,0,n)

void solve(ll m, ll d){
    int ans=0;
    fori(i,1,d+1){
        int d1=i/10;
        int d2=i%10;
        if(d1>=2&&d2>=2&&d1*d2<=m)ans++;
    }
    cout<<ans<<endl;
}

int main(){
    ll m;
    scanf("%lld",&m);
    ll d;
    scanf("%lld",&d);
    solve(m, d);
    return 0;
}
