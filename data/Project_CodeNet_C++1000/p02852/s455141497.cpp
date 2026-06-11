#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll MAXN=1e5+69;
ll n,m;
string s;
ll L[MAXN];
void bye(){
    cout<<-1;
    exit(0);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>s;
    if(s[0]=='1'||s[n]=='1')bye();
    deque<ll>dq={0};
    for(ll i=1;i<=n;i++){
        if(s[i]=='1')continue;
        while(!dq.empty()&&i-dq.front()>m)dq.pop_front();
        if(dq.empty())bye();
        L[i]=dq.front();
        dq.push_back(i);
    }
    ll id=n;
    vector<ll>ans;
    while(id>0){
        ans.push_back(id-L[id]);
        id=L[id];
    }
    while(!ans.empty())cout<<ans.back()<<' ',ans.pop_back();
}