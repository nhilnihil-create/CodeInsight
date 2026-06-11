#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define N 2005
#define INF 1000000005
#define INFLL (long long)1e18
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
    ll ans=1;
    ll m=INFLL;
    REP(i,n){
        ll a;
        cin>>a;
        if(a==0){
            ans=0;
            break;
        }
        if(a<=m){
            ans*=a;
            m/=a;
        }else{
            ans=-1;
        }
    }
    OUT(ans);
    return 0;
}
