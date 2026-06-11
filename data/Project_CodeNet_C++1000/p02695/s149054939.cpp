#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define debug  freopen("in.txt","r",stdin),freopen("out.txt","w",stdout);
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn = 1e6+10;
const int maxM = 1e6+10;
const int inf = 0x3f3f3f3f;

ll N,M,Q;
struct node
{
    ll a,c,d;
};
struct node2
{
	ll a,b,c,d;	
}qq[maxn];
vector<node> adj[maxn]; 
ll A[maxn];
ll res = 0;
int B[maxn],tail = 0;
void dfs(int id,int last = 1){
    if(id > N){
       	ll sum = 0;
       	for(int i = 1;i<=N;i++){
       		if(adj[i].size() == 0) continue;
       		for(auto no:adj[i]){
       			if(A[i] - A[no.a] == no.c) sum += no.d;
       		}
       	}
       	res = max(res,sum);
        return ;
    }
    A[id] = last;
    dfs(id+1,last);
    for(auto no:adj[id]){
        ll cur = A[no.a] + no.c;
        if(cur > M || cur < last) continue;
        else{
            A[id] = cur;
            dfs(id+1,cur);
        }
    }
}

int main(){
    // debug;
    ios;

    cin>>N>>M>>Q;
    for(int i = 1;i<=Q;i++){
        ll a,b,c,d; cin>>a>>b>>c>>d;
        adj[b].pb({a,c,d});
        qq[i] = {a,b,c,d};
    }
    dfs(1);
    cout<<res<<'\n';
    return 0;
}
