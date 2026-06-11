#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forin(in, n) for(int i=0; i<n; i++) cin>>in[i]
#define forout(out, n) for(int i=0; i<n; i++) cout<<out[i]<<endl
#define rep(i, n) for(int i=0; i<(n); i++)

int main(){
    int n, m; cin>>n>>m;
    vector<int> h(n);

    forin(h, n);

    vector<bool> good(n, true);

    rep(i, m){
        int a, b;
        cin>> a >> b;
        a--;
        b--;

        if(h[a] <= h[b]) good[a] = false;
        if(h[b] <= h[a]) good[b] =false;
    }
    int ans=0;
    rep(i, n) if(good[i]) ans++;

    cout<<ans<<endl;
}