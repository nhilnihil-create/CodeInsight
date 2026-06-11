#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)




using namespace std;
using ll = long long;
using P = pair<int,int>;
using ull= unsigned long long;
const ll K_MAX=1e5+5;
const ll Lmax=ll(1e18);
const ll Nmax=1e9;



int main(){
  string s;
  cin>>s;
  auto n=size(s);
  map<int,int> nr,nl; //group iのr数，l数．
  map<int,int> pr; //group iの最終r位置．
  vector<int> ans(n); //最終位置．
  
  rep(i,n){
    ans[i]=0;
  }
  
  
  int g=0;
  char prev='R';
  int nturn=0;
  
  rep(i,n){
    if(s[i]==prev){
      if(s[i]=='R'){
        //cout<<"R"<<endl;
        nr[g]++;
      }else{
        nl[g]++;
      }
    }else{
      nturn++;
      if(nturn%2==0){
        g++;
        nr[g]+=1;
      }else{
        pr[g]=i-1;
        nl[g]+=1;
      }
    }
    prev=s[i];
  }
  
  g=0;
  rep(i,size(pr)){
    ans[pr[i]]=(nr[i]+1)/2+nl[i]/2;
    ans[pr[i]+1]=(nr[i])/2+(nl[i]+1)/2;    
    g++;
  }
  rep(i,n){
    cout<<ans[i]<<" ";
  }
  
  








}
