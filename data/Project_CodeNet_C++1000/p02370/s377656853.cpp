#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(a)  (a).begin(),(a).end()
#define vi vector<int>
#define pb push_back
#define INF 999999999
//#define INF (1LL<<59)

#define MAX_V 10000
vector<int> G[MAX_V];


int main(){
    int v,e;
    cin>>v>>e;
    vector<int> in_deg(v,0);
    vector<int> list;
    
    rep(i,e){
        int s,t;
        cin>>s>>t;
        in_deg[t]++;
        G[s].pb(t);
    }
    
    stack<int> st;
    rep(i,v)if(in_deg[i]==0)st.push(i);
    
    while(st.size()){
        int q = st.top();
        st.pop();
        list.pb(q);
        
        rep(i,G[q].size()){
            int to = G[q][i];
            in_deg[to]--;
            if(in_deg[to]==0)st.push(to);
        }
    }
    
    rep(i,list.size())cout<<list[i]<<endl;
    
    if(list.size()!=v){/*????????????*/}
}