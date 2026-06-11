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
    set<int> b;
    rep(i,n){
        cin>>a[i];
        b.insert(a[i]);
    }

    sort(all(a));
    vector<bool> ok(1000010,true);
    rep(i,n-1){
        if(a[i]==a[i+1]) ok[a[i]]=false;
    }
    
    for(auto x : b){
        for(int j=2*x;j<1000010;j+=x) ok[j]=false;
    }
    

    int ans=0;
    for(auto x : b){
        if(ok[x]){
            ans++;
            //cout<<a[i]<<endl;
        }
    }

    cout<<ans<<endl;
}