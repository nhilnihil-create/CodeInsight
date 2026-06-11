#include <bits/stdc++.h>
#include<numeric>
#include<cstdlib>
#include <iostream>
#define ll long long int
#define all(x) x.begin(),x.end()

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define v vector<long long int> 
#define vv vector< int> 
#define gcd(m,n) __gcd(m,n)
#define vp vector<pair<long long int ,long long int>>
#define pb push_back
#define mp make_pair
#define pp pop_back
#define iter vector<int>::iterator
#define pa pair<long long int ,long long int> 
#define f(i,n) for(ll i=0;i<n;i++)
#define loop(i,a,n) for (ll i=a ; i<n ;i+=1)
#define fe(d,e) for(auto d:e)
#define mod 1000000007
#define F first
#define S second
#define sett set<long long int>
#define um unordered_map<ll,ll>
# define N 100005LL
# define cout1(x) cout<<x<<"\n";
# define  deb(x) cout<<#x<<" "<<x<<"\n";
#define  vii vector<pa>;
using namespace std;

v visited(N);
vector<ll> ans={-1};
v level(N);
v ind(N);
ll sz[N];




// void dfs(ll node, ll par){
    
//     visited[node]=1;
//     if (node==1)level[1]=0;
//     else level[node] = level[par]+1;
//     ans.pb(node);
//     for(auto x:graph[node]){
//         if (!visited[x]){
//             dfs(x,node);
//             sz[node]+=sz[x];

//         }
       
//     }
//      ++sz[node];
    
// }
// map<ll,ll> cnt;
// ll answer(ll ans,ll x){
//     cout<<ans<<" "<<x<<endl;
//     if (cnt[ans%x]==0)return ans;
//     else if (cnt[ans%x==1] && ans>x)return ans;
//     else{
//         cnt[ans%x]-=1;
//         cnt[ans]+=1;
//         answer(ans+1,x);
//     }



// }

int main(){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll ans=1;
    loop(i,1,n){
        if (s[i]!=s[i-1])ans+=1;
    }
    cout1(ans);
}
  
    
    

        
