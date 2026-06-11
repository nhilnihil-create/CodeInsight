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
       cin>>N;
       vector<Int> A(N);
       
       for(auto &x:A) cin>>x;
       Int ans=0;
       sort(A.begin(),A.end());
       for(int i=0;i<N;++i){
           for(int j=i+1;j<N;++j){
               for(int k=j+1;k<N;++k){
                   bool ok=true;
                   if(A[i]+A[j]<=A[k]) ok=false;
                   if(A[i]+A[k]<=A[j]) ok=false;
                   if(A[k]+A[k]<=A[j]) ok=false;
                   if(A[i]==A[j]||A[j]==A[k]||A[i]==A[k]) ok=false;
                   ans+=ok;
               }
           }
       }
       cout<<ans<<"\n";
}