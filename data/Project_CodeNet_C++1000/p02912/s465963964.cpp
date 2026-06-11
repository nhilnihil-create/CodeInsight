#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using product = pair<ll,ll>;
using graph = vector<vector<ll>>;
using vll = vector<ll>;
 
template <class type> void printVector(vector<type> vec){
    stringstream ss;
    for(ll i=0;i<vec.size();i++)
    {
        ss<<vec[i]<<" ";
        if(i!=vec.size()-1)ss<<" ";
    }
    cout<<ss.str()<<endl;
}

void solve(){
    ll N,M;
    cin>>N>>M;
    vll A(N,0);
    priority_queue<ll> que;
    for(ll i=0;i<N;i++){
        ll a;cin>>a;que.push(a);
    }
    for(ll i=0;i<M;i++)
    {
        ll discounted=que.top()/2;
        que.pop();
        que.push(discounted);
    }
    ll res = 0;
    for(ll i=0;i<N;i++)
    {
        res+=que.top();
        que.pop();
    }
    cout<<res;
}
 
int main(){
    solve();
    return 0;
}