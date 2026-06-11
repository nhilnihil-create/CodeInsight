#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define repa(i,a,n) for(int i=(a);i<(n);i++)
#define rrep(i,n) for(int i=n;i>=0;i--)
#define rrepa(i,a,n) for(int i=n;i>=(a);i--)
#define all(a) (a).begin(),(a).end()
#define MOD 1000000007
#define cmax(a,b) a=max(a,b)
#define cmin(a,b) a=min(a,b)
#define vc vector

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;



int main(){

    int n,d;
    cin>>n>>d;

    vvi x(n,vi(d));
    rep(i,n)rep(j,d)cin>>x[i][j];
    int ans=0;

    rep(i,n-1)repa(j,i+1,n){
        int dis=0;
        rep(k,d)dis+=(x[i][k]-x[j][k]) * (x[i][k]-x[j][k]);
        int a=1;
        while(true){
            if(a*a == dis)ans++;
            if(a*a >= dis)break;
            a++;
        }
    }

    cout<<ans<<"\n";

    return 0;

}