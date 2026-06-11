#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forin(in, n) for(int i=0; i<n; i++) cin>>in[i]
#define forout(out) for(int i=0; i<(int)out.size(); i++) cout<<out[i]<<endl
#define rep(i, n) for(int i=0; i<(n); i++)
 
int main(){
    int n; cin>> n;
    vector<ll> h(n);
    int ans=0;
    int cnt=0;
    forin(h, n);
    for(int i=0; i<n-1; i++){
        if(h[i] >= h[i+1]){
            cnt++;
        }else{
            cnt=0;
        }
        ans=max(cnt, ans);
    }
    cout<<ans<<endl;
}