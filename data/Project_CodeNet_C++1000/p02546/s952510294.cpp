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
    string s;
    cin>>s;
    lli n = s.size();
    if(s[n-1]=='s'){
        cout<<s<<"es";
    }else{
        cout<<s<<"s";
    }
}
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    cout<<"\n";
    
 
    return 0;
}