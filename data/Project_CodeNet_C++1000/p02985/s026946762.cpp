#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,a,b) for(int i=a;i<b+1;i++)
#define Per(i,b,a) for(int i=b;i>=a;i--)

ll frac[100000];
ll inv_frac[100000];

ll binary_method(ll a,ll b){
    if(b==0) return (ll)1;
    ll temp = binary_method(a,b>>1);
    if(b%2) return (((temp*temp)%mod)*a)%mod;
    else return (temp*temp)%mod;
}
ll inv(ll a){
    return binary_method(a,mod-2);
}


ll dfs(vector<int> *edge, int N,ll K,int pos,int parent){
    if(edge[pos].size()==1 && parent != -1) return (ll) 1;
    int child_num ;
    ll ans;
    if(parent==-1){
        child_num = edge[pos].size();
        ans = (frac[K-1]*inv_frac[K-1-child_num])%mod;
    } 
    else {
        child_num = edge[pos].size()-1;
        ans = (frac[K-2]*inv_frac[K-2-child_num])%mod;
    }
    // cout<<ans<<endl;
    rep(i,edge[pos].size()){
        int now_pos = edge[pos][i];
        if(now_pos == parent) continue;
        ans = (ans * dfs(edge,N,K,now_pos,pos)) % mod;
    }
    // cout<<pos<<" "<<ans<<endl;
    return ans;
}

int main(){
    int N;
    ll K;
    cin>>N>>K;
    vector<int> edge[100000];
    int a,b;
    rep(i,N-1){
        cin>>a>>b;
        a--;b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    if(K==1){
        if(N!=1) cout<<0<<endl;
        else cout<<1<<endl;
        return 0;
    }
    int max_deg = 0;
    rep(i,N) max_deg = max(max_deg,(int)edge[i].size()+1);
    if(max_deg>K) {cout<<0<<endl; return 0;}

    frac[0] = 1;
    Rep(i,1,K-1) frac[i] = frac[i-1]*i %mod;
    rep(i,K) inv_frac[i] = inv(frac[i]); 
    ll ans = dfs(edge,N,K,0,-1);
    ans = (ans*K)%mod;

    cout<<ans<<endl;
    return 0;
}