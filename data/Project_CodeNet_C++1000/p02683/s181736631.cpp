#include <bits/stdc++.h>

using namespace std;
using Graph = vector<vector<int>>;
using Grid= vector<vector<char>>;
using vin= vector<int>;
using ll=long long;
using vll= vector<ll>;
using vbl=vector<bool>;
using vch=vector<char>;
using pinin=pair<int ,int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rell(i,n) for (ll i=0; i< (ll)(n); i++)
#define sort(x) sort(x.begin(), x.end());
#define rese(x) reverse(x.begin(), x.end());
#define vnn(x,y,name) vector<vector<int>> name(x, vector<int>(y));

string yes="Yes",no="No";

int main() {
    int n,m,x;
    cin>>n>>m>>x;
    vin c(n);
    vnn(n,m,a);
    rep(i,n){
        cin>>c[i];
        rep(j,m){
            cin>>a[i][j];
        }
    }
    bool ok=false;
    int ans=1001001001;
    rep(i,4096){
        bitset<12> hant(i);
        vin cnt(m,0);
        int ansa=0;
        rep(j,n){
            if(hant[j]){
                rep(k,m){
                    cnt[k]+=a[j][k];
                }
                ansa+=c[j];
            }
        }
        bool allok=true;
        rep(j,m){
            if(cnt[j]<x) allok=false;
        }
        if(allok){
            ok=true;
            ans=min(ans,ansa);
        }
        
    }
    if(ok) cout<<ans<<endl;
    else cout<<-1<<endl;
  

}
