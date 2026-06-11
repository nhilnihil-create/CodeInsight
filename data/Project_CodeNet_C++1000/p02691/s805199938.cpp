#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)

using namespace std;
using ll = long long;
using P = pair<int,int>;
using ull= unsigned long long;
const ll K_MAX=1e5+5;


int main(){
  map<int,int> l,r;
  int n;
  cin>>n;
  
  ll ans=0;

  rep(i,n){
    int a;
    cin>>a;
    l[i+1-a]++;
    r[i+1+a]++;
 
    //cout<<ans<<endl;
    if(r.find(i+1-a)==r.end()){
      continue;
    }else{
      ans+=r[i+1-a];
    }
    
    
  }    
 cout<<ans<<endl;

}

