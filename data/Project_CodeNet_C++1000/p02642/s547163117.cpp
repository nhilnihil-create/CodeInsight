#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,n) cin>>a[i];

    sort(all(a));
    vector<bool> ok(1000010,false);

    rep(i,n){
        if(ok[a[i]]) continue;
        for(int j=2*a[i];j<=a[n-1];j+=a[i]) ok[j]=true;
        if(a[i]==a[i+1]) ok[a[i]]=true;
    }

    int ans=0;
    rep(i,n){
        if(!ok[a[i]]){
            ans++;
            //cout<<a[i]<<endl;
        }
    }

    cout<<ans<<endl;
}