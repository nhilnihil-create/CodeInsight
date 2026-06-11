#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
  ll n;
  cin >> n;
  vector<string> s(n);
  map<string, ll> ma;
  
  for(int i=0; i<n; i++){
    cin >> s[i];
    ma[s[i]]++;
  }
  
  ll max_num = ma[s[0]];
  for(int i=1; i<n; i++){
    if(max_num<ma[s[i]]){
      max_num = ma[s[i]];
    }
  }
  
  for(auto i:ma){
    if(i.second==max_num){
      cout << i.first << endl;
    }
  }
  
  return 0;
}