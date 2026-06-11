#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;

int main(){
  ll n,k,r,s,p;
  string t;
  cin>>n>>k>>r>>s>>p>>t;
  ll point=0;
  vector<ll>v1(t.size());
  
  for(ll i=0;i<t.size();i++){
    if(t[i]=='r'){
      point+=p;
    }
    else if(t[i]=='s'){
      point+=r;
    }
    else{
      point+=s;
    }
  }
  
  
  for(ll i=t.size()-1;i>=k;i--){
    if(t.at(i)==t.at(i-k)){
      if(v1.at(i)%2==0){
      v1.at(i-k)+=v1.at(i)+1; 
        if(t[i]=='r'){
      point-=p;
    }
        else if(t[i]=='s'){
      point-=r;
    }
        
        else{
      point-=s;
        }
        
      }
      
      else{
        v1.at(i-k)+=v1.at(i)+1;
      }
    }
       
  }
       cout<<point<<endl;
       
     
       
}
       
        
      
  
    