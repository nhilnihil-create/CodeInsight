#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#define Int long long
#define pb push_back
using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> 

Int N,M,K;

const int MOD=(int)(1e9+7);
const int MAXN=500005;
vector<Int> adj[MAXN];
vector<Int> degree;
bool VIS[MAXN];     

int main()
{
        string S;cin>>S;
        Int ans=0;Int cons=0;
        for(int i=0;i<S.length();++i){
            if(S[i]=='R') ++cons,ans=max(ans,cons);
            else{
                cons=0;
            }
        }
        cout<<ans<<"\n";
}