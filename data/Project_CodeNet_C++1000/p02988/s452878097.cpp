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

    int n;
    cin>>n;
    vi p(n);
    rep(i,n)cin>>p[i];

    int ans=0;
    repa(i,1,n-1){
        if((p[i]>p[i-1] && p[i]<p[i+1]) || (p[i]<p[i-1] && p[i]>p[i+1]))ans++;
    }

    cout<<ans<<"\n";

    return 0;

}