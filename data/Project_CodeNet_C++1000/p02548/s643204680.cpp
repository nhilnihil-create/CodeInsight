#include<bits/stdc++.h>
typedef long long int lli;

#define em emplace_back
#define rep(i,j,n) for(lli i=j;i<n;i++)
#define repf(i,a,j,n) for(lli i=j,a=0;i<n;i++,a++)
#define repg(i,j,n) for(int i=j;i>n;--i)
using namespace std;

void dbg(vector<long long int > v){
  for(long long int i = 0 ; i<v.size(); ++i){
   cerr<<v[i]<<" ";
  }
  cerr<<endl;
}
void prt(vector<long long int > v){
  for(long long int i = 0 ; i<v.size() ; ++i){
   cout<<v[i]<<" "; 
  }
  cout<<endl;
}
 
void solve(){
    lli n;
    cin>>n;

    lli ans = 0;
    rep(i,1,n+1){
        rep(j,1,n+1){
            if(i*j<n){
                ans++;
            }else{
                break;
            }
        }
    }

    cout<<ans;
}
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    
 
    return 0;
}