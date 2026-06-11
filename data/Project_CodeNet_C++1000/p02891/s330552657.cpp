#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  string S;ll K,ans,l=1;
  cin >> S >> K;
  vector<pair<char,ll>> v;
  for(ll i=0;i<S.length();i++){
    if (i==0)continue;
     if(S[i] == S[i-1]) l++;
     else{
       v.push_back(make_pair(S[i-1],l));
       l=1;
     }
    if (i==S.length()-1) v.push_back(make_pair(S[i],l));
  }
  if (S.length() == 1)v.push_back(make_pair(S[0],1));
  
  ans = 0;
  
  if (v.size() == 1) ans=v[0].second * K / 2;
   else{
    for(ll i=1;i<v.size()-1;i++){
      ans+=v[i].second/2 * K;
    }
     if (v[v.size()-1].first == v[0].first){
       ans +=(v[0].second + v[v.size()-1].second)/2 * (K-1);  
    	ans += v[v.size()-1].second/2;
       ans += v[0].second/2;
     }else{
      ans += v[v.size()-1].second/2 * K;
       ans += v[0].second/2 * K;
     }
   }
 
  cout << ans << endl;
  
}