#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    rep(i,n) cin>>a[i];

    while(k--){
        vector<int> b(n+1,0);

        rep(i,n){
            b[max(i-a[i],0)]++;
            b[min(i+a[i]+1,n)]--;            
        }
        rep(i,n){
            b[i+1]+=b[i];
        }
        /*
        rep(i,n) cout<<b[i]<<" ";
        cout<<endl;
        */
        rep(i,n){
            a[i]=min(b[i],n);
        }
        bool ok=true;
        rep(i,n){
            if(a[i]!=n) ok=false;
        }
        if(ok){
            rep(i,n) cout<<a[i]<<" ";
            cout<<endl;
            return 0;
        }
    }

    rep(i,n){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}