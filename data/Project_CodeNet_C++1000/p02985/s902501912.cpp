#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int inf=1<<30;
const int mod=1e9+7;
const int MOD=998244353;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,k;cin >> n >> k;
    vector<vector<int>> g(n);
    for(int i=0;i<n-1;i++){
        int a,b;cin >> a >> b;
        a--,b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    stack<int> st;
    ll ans=k;
    vector<bool> vis(n);
    vis[0]=true;
    st.push(0);
    while(!st.empty()){
        int p=st.top();
        st.pop();
        ll cnt=0;
        for(int x:g[p]){
            if(vis[x]){
                continue;
            }
            if(p==0){
                (ans*=k-1-cnt)%=mod;
            }
            else{
                (ans*=k-2-cnt)%=mod;
            }
            cnt++;
            st.push(x);
            vis[x]=true;
        }
    }
    cout << ans << endl;
}