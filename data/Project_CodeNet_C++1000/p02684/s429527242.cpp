#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define FORC(i,a,b,c) for(ll i=(a);i<(b);i+=(c))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ff first
#define ss second
#define dd long double

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k;
    cin>>n>>k;
    vector<ll> graph[n];
    REP(i,n){
        graph[i].clear();
    }
    REP(i,n){
        ll u;
        cin>>u;
        u--;
        graph[i].pb(u);
    }
    map<ll,ll> s;
    vector<ll> ord;
    ord.pb(0);
    stack<ll> st;
    s[0]=0;
    st.push(0);
    ll i=1;
    ll pos;
    while(1){
        ll from=st.top();
        st.pop();
        ll to=graph[from][0];
        if(s.count(to)){
            pos=s[to];
            break;
        }
        st.push(to);
        ord.pb(to);
        s[to]=i;
        i++;
    }
    vector<ll> rep(ord.begin()+pos,ord.end());
    if(k<pos){
        cout<<ord[k]+1<<endl;
    }
    else{
        k-=pos;
        k%=rep.size();
        cout<<rep[k]+1<<endl;
    }
}
