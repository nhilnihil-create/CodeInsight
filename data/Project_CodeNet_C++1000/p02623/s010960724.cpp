#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) for (int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define MOD 1000000007
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
const int INFTY =2147483647;
int main(){
    ll n,m,k,a=0,b=0;
    int ans=0;
    ll A[200005],B[200005];
    cin>>n>>m>>k;
    REP(i,n) cin>>A[i];
    REP(i,m){
        cin>>B[i];
        b+=B[i];
        if(b<=k) ans++;
    }
    int i=0,j=m-1;

    while(i<=n-1 && a+A[i]<=k){

        a+=A[i];
        while(j>=0 && b>k-a){
            b-=B[j];
            j--;
        }
        ans=max(ans,i+j+2);
        i++;
    }
    cout<<ans<<endl;
}