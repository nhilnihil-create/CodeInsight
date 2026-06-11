#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  int n;
  cin >> n;
  map<string,int> mp;
  rep(i,n){
    string s;
    cin >>s;
    sort(s.begin(),s.end());
    mp[s]++;
  }
  long long ans=0;
  for(auto p:mp){
    int q=p.second;
    for(int i=1;i<=q-1;i++){
      ans+=i;
    }
  }
  cout <<ans;
}