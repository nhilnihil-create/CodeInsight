#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define N 2005
#define INF 1000000005
#define INFLL 2000000000000000003
#define PI 3.1415926535897
typedef long long ll;
#define ALL(v) (v).begin(),(v).end()
#define SZ(x) int(x.size())
#define IN(a) cin>>(a)
#define OUT(a) cout<<(a)<<endl
typedef pair<int,int> P;
const int MAX = 1000005;
const int MOD = 1000000007;
int main(){
    int n;
    cin>>n;
    vector<int>a(n+1);
    REP(i,n+1)cin>>a[i];
    vector<ll>m(n+1);
    m[0]=1-a[0];
    bool f=true;
    REP(i,n){
        m[i+1]=2*m[i]-a[i+1];
        if(m[i+1]>INFLL)m[i+1]=INFLL;
        if(m[i+1]<0)f=false;
    }
    if(m[0]<0)f=false;
    vector<ll>d(n+1);
    d[n]=a[n];
    for(int i=n-1;i>=0;i--){
        if(d[i+1]<=m[i]){
            d[i]=d[i+1]+a[i];
        }else{
            d[i]=m[i]+a[i];
        }
    }
    ll ans=0;
    REP(i,n+1){
        ans+=d[i];
    }
    if(!f)ans=-1;
    OUT(ans);
    return 0;
}
