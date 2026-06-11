#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

vector<vector<ll> > vc;


int main(){

    ll N,Q;
    cin>>N>>Q;
    vc.resize(N);

    
    ll a,b;

    for(ll i=0;i<N-1;++i){
        cin>>a>>b;
        --a;--b;
        vc[a].push_back(b);
        vc[b].push_back(a);
    }
    vector<ll> ans(N,0);
    vector<bool> vis(N,false);

    ll p,x;

    for(ll i=0;i<Q;++i){
        cin>>p>>x;
        --p;
        ans[p]+=x;
    }
       
        stack<ll> st;
        st.push(0);
        
        while(!st.empty()){
            ll now=st.top();
           // cout<<"p: "<<p<<endl;
            st.pop();
            vis[now]=true;

            for(ll j=0;j<vc[now].size();j++){
                ll next=vc[now][j];
                if(vis[next]!=true){
                st.push(next);
                ans[next]+=ans[now];
                }
            }
        }


    for(ll i=0;i<N;++i){
        cout<<ans[i]<<endl;
    }
}
