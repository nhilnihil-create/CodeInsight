#include<bits/stdc++.h>
using namespace std;
#define all(vec) vec.begin(),vec.end()
typedef long long int ll;
typedef pair<int,int> P;
const ll MOD=1000000007;
const ll INF=1000000010;
const ll LINF=4000000000000000010LL;
const int MAX=310;
const double EPS=1e-9;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
vector<int> toposort(int n,vector<int> G[],int h[]){
    stack<int> st;
    vector<int> res;
    for(int i=0;i<n;i++){
        if(!h[i])st.push(i);
    }
    while(!st.empty()){
        int id=st.top();
        st.pop();
        res.push_back(id);
        for(auto e:G[id]){
            h[e]--;
            if(!h[e])st.push(e);
        }
    }
    return res;
}
int main(){
    int n,m;cin>>n>>m;
    vector<int> G[10010];
    int h[10010];
    for(int i=0;i<m;i++){
        int s,t;cin>>s>>t;
        G[s].push_back(t);
        h[t]++;
    }
    vector<int> ans=toposort(n,G,h);
    for(auto e:ans){
        cout<<e<<endl;
    }
}

