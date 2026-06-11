#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define N 501
#define M 1000000007
using namespace std;
ll a[N][N], v[N],k=0,n;
bool f[N*N];
vector<pair<ll,ll>>temp;
void dfs(int i){
    for(ll j=1; j<=n; ++j)
        if(!a[i][j] && i!=j){
            if(v[j]==-1){ //cout<<i<<" "<<j<<" "<<k<<"\n";
                a[i][j]=a[j][i]=k+1;
                v[j]=v[i]+1;
                for(ll t=1; t<=n; ++t)
                    f[a[j][t]]=1;
                temp.push_back({i,j});
                dfs(j);
            }
            else if((v[j]+v[i])%2==1){//cout<<i<<" "<<j<<" "<<k<<".\n";
                a[i][j]=a[j][i]=k+1;
                for(ll t=1; t<=n; ++t)
                    f[a[j][t]]=1;
                temp.push_back({i,j});
            }
        }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll i,j,t;
    cin>>n;
    for(i=1; i<=n; ++i){
        for(j=1; j<=n; ++j){
            if(!a[i][j] && i!=j){
                temp.clear();
                for(t=1; t<=n; ++t)
                    v[t]=-1;
                for(t=1; t<=k; ++t)
                    f[t]=0;
                v[i]=0;
                a[i][j]=a[j][i]=k+1;
                //cout<<i<<" "<<j<<" "<<a[i][j]<<";\n";
                v[j]=1;
                dfs(j);
                ll gasit=k+1;
                for(t=1; t<=k && gasit==k+1; ++t)
                    if(!f[t])
                        gasit=t;
                if(gasit==k+1) ++k;
                for(auto it:temp)
                    a[it.f][it.s]=a[it.s][it.f]=gasit;
            }
        }
    }
    for(i=1; i<=n; ++i){
        for(j=i+1; j<=n; ++j)
            cout<<a[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}
