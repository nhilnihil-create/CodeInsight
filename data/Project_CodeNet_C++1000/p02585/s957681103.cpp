#include <bits/stdc++.h>
    #include <math.h>
 
    using namespace std;
    typedef long long ll;
    typedef unsigned long long ull;
    # define M_PI  3.14159265358979323846
 
 
    const int M=1e9+7;
    long long mod(long long x){
        return ((x%M + M)%M);
    }
    long long add(long long a, long long b){
        return mod(mod(a)+mod(b));
    }
 
    vector<ll>a(5005);
    vector<ll>b(5005);
    vector<ll>track;
    bool vis[5005];
 
    void dfs(int u , long long total_cycle){
        if(vis[u]) return ;
        vis[u]=true;
        total_cycle+=b[u];
        track.push_back(total_cycle);
        dfs(a[u],total_cycle);
    }
    void solve(){
        int n,k;
        cin>>n>>k;
        for(int i=0;i<n;i++){
            cin>>a[i];
            a[i]--;
        }
        for(int i=0;i<n;i++)
            cin>>b[i];
        ll ans=-(1e18);
        for(int i=0;i<n;i++){
            memset(vis,false,sizeof(vis));
            dfs(i,0);
            if(track.back()>0 && k>=(int)(track.size())){
                ll cycles=(ll)(k/(int)track.size());
                ll left=(ll)(k%(int)track.size());
                ll maxi=-1e18;
                for(int x=0;x<(int)track.size();x++)
                    maxi=max(maxi,track[x]);
                ans=max(ans,(cycles-1LL)*(track.back())+maxi);
                maxi=-1e18;
                for(int x=0;x<left;x++)
                    maxi=max(maxi,track[x]);
                ans=max(ans,(cycles*track.back()) + maxi);
            }
            else{
                for(int j=0;j<(min((int)track.size(),k));j++){
                    ans=max(ans,track[j]);
                }
            }
            track.clear();
        }
        cout<<ans;
        return;
    }
    int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cout<<fixed;
        cout<<setprecision(10);
//        freopen("timber_input.txt", "r", stdin);
//        freopen("timber_output.txt", "w", stdout);
        int t=1;
        // cin>>t;
        for(int i=1;i<=t;i++){
//            cout<<"Case #"<<i<<": ";
            solve();
        }
        return 0;
    }