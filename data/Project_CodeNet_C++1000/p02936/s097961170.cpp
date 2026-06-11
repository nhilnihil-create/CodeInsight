#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i=0;i<(n);i++)
#define rep2(i,n) for(long long i=1;i<=(n);i++)
#define rep3(i,i0,n) for(long long i=i0;i<(n);i++)
#define all(x) x.begin(), x.end()
#define pb push_back
#define mod 1000000007
#define INF 2000000000
typedef long long ll;
bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.first != b.first){
        return a.first < b.first;
        
    }else{
        return a.second < b.second;
    }
}
// 入力
vector<ll> ans(100);
/*void renew(vector<vector<ll>> tree,ll key,ll parent,ll flag, ll p, ll x){//TLE
    if(flag == 1 || key == p){
        ans[key]+=x;
        flag = 1;
    }
    rep(i,tree[key].size()){
        //cout <<tree[key][i] << endl;
        if(tree[key][i] != parent){
            
            renew(tree,tree[key][i],key,flag,p,x);
        }
    }
}*/

/*vector<ll> parents(100);
void know_parent(vector<vector<ll>> tree, ll key, ll root){
    parents[key] = root;
    rep(i,tree[key].size()){
        if(tree[key][i] != root){
            know_parent(tree,tree[key][i],key);
        }
    }
}*/
vector<vector<ll>> t(100);
void renew(ll key,ll parent){
    rep(i,t[key].size()){
        if(t[key][i] != parent){
            ans[t[key][i]] += ans[key];
            renew(t[key][i],key);
        }
    }
}

int main() {
    
    ll N,Q;
    cin >> N >> Q;
    
    ans.resize(N);
    t.resize(N);
    ll a,b;
    rep(i,N-1){
        cin >>a>>b;
        a--;
        b--;
        t[b].pb(a);
        t[a].pb(b);
    }

    ll p,x;
    rep(i,Q){
        cin >> p >>x;
        p--;
        ans[p] += x;
    }

    
    //know_parent(t,0,-1);
    renew(0,-1);
 

    rep(i,N){
        cout << ans[i] << " ";
    }
    cout << endl;
    
    
    
    
    return 0;
    

}