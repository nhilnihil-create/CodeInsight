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
    int n,m,q;
    cin>>n>>m>>q;
    vin a(q),b(q),c(q),d(q);
    rep(i,q) cin>>a[i]>>b[i]>>c[i]>>d[i];
    int ans=0;
    rep(i,524288){
        bitset<19> s(i);
        int j=0;
        int look=0;
        int sumd=0;
        
        vin ax(n,1);
        bool ok=true;
        while(ok){
            if(s[look]==0){
                ax[j]++;
                if(ax[j]>m){
                    ok=false;
                    break;
                }
            }
            else if(j<n-1){
                ax[j+1]=ax[j];
                j++;
            }
            else break;
            
            look++;
        }
        if(!ok) continue;
        rep(j,q){
            if(ax[b[j]-1]-ax[a[j]-1]==c[j]) sumd+=d[j];
        }
        ans=max(sumd,ans);
    }
    cout<<ans<<endl;
    

}
