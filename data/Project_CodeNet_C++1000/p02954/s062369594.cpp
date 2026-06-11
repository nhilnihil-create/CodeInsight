#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fo(i,s,e) for( i=s;i<e;i++)
#define rfo(i,s,e) for(i=s;i>e;i--)
#define LLI long long int
#define LI long int 
const LI MOD=1e9+7;
#define pb push_back
#define pob pop_back()
#define sp " "
#define ff first
#define ss second
//            When something is important enough, you do it even if the odds are not in your favor.

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    // code goes here
    int t=1;//cin>>t;
    while(t--){
      string s;cin>>s;
      LI n=s.length(),i;
      LI l[n],r[n];
      l[n-1]=n-1,r[0]=0;
      rfo(i,n-2,-1){
        if(s[i]=='L') l[i]=i;
        else l[i]=l[i+1];
      }
      fo(i,1,n){
        if(s[i]=='R') r[i]=i;
        else r[i]=r[i-1];
      }
      std::vector<LI> v(n,0);
      fo(i,0,n){
        if(s[i]=='R'){
          LI len=l[i]-i;
          if(len&1) v[i+len-1]++;
          else v[i+len]++;
        }
        else{
          LI len=i-r[i];
          if(len&1) v[i-len+1]++;
          else v[i-len]++;
        }
      }
      for(auto x:v) cout<<x<<sp;
    }
    return 0;
}