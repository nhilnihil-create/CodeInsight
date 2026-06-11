#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0; i<(int)(n); i++)
using graph = vector<vector<char>>;

int main(){
  string s;cin>>s;
  ll n=s.size()+1;
  vector<ll> v(n,-1);
  
  rep(i,n){
    if(i==0&&s.at(0)=='<'){v[i]=0;}
    else if(i==n-1&&s.at(n-2)=='>'){v[i]=0;}
    if (i>0&&i<n-1){
      if(s.at(i-1)=='>' && s.at(i)=='<'){
      v[i]=0;
      }
    }
    
    if(v[i]==0){
      ll j=i;
      if(j<n-1){
        while(s.at(j)=='<'){
          v[j+1]=v[j]+1;j++;
          if(j==n-1){break;}
        }
      }
               
      j=i;
      if(j>0){
        while(s.at(j-1)=='>'){
          v[j-1]=v[j]+1;j--;
          if(j==0){break;}
        }
      }
    }
  }
  rep(i,n-2){
    
   if(s.at(i)=='<'&&s.at(i+1)=='>'){v[i+1]=max(v[i],v[i+2])+1;}
  }
  ll ans=0;
  rep(i,n)ans+=v[i];
  cout<<ans;

}


