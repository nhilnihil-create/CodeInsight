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
    lli current = 0;
    lli flag = false;
    rep(i,0,n){
        lli a,b;
        cin>>a>>b;
        if(a==b){
            current++;
        }else{
            current = 0;
        }

        if(current==3){
            flag = true;
        }
    }
    if(flag){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
}
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    
 
    return 0;
}