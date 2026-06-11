#include<bits/stdc++.h>
using namespace std;
using ll=int64_t;
int main(){
  string s,t;
  cin>>s>>t;
  ll l=s.length(),m=t.length(),r=0,c=-1,j;
  vector<vector<ll>> v(26);
  for(j=0;j<l;j++) v[s[j]-'a'].push_back(j);
  for(j=0;j<m;j++){
    if(v[t[j]-'a'].size()==0){
      cout<<-1<<endl;
      return 0;
    }
    auto it=upper_bound(v[t[j]-'a'].begin(),v[t[j]-'a'].end(),c);
    if(it==v[t[j]-'a'].end()){
      r++;
      c=*v[t[j]-'a'].begin();
    }
    else c=*it;
  }
  cout<<r*l+c+1<<endl;
}