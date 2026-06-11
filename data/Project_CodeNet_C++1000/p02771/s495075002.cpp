#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
int main(){
 ll a,b,c;
  cin>>a>>b>>c;
  map<ll,int> mp;
  mp[a]++;
  mp[b]++;
  mp[c]++;
  auto it = mp.begin();
  while(it!=mp.end()){
   if(it->second==2){
   cout<<"Yes\n";
     return 0;
  }
   it++;
}
 cout<<"No\n";
return 0;
}
