#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef pair<int,int> P;
const int INF=1e9;
int main(){
    int n,now=1,ans=0;
    cin>>n;
    vector<int> a(n);
    rep(i,n) cin>>a[i];
    for(int i=0;i<n;i++){
        if(a[i]==now){
            now++;
        }
        else ans++;
    }
    if(ans==n) cout<<"-1";
    else cout<<ans;
}