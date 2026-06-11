#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  long long K=0;
  map<string,long long>mp;
  cin>>N;
  vector<string>v(N);
  for(int X=0;X<N;X++){
    cin>>v[X];
    sort(v[X].begin(),v[X].end());
    mp[v[X]]++;
  }
  for(auto p:mp){
    auto V=p.second;
    K+=V*(V-1)/2;
  }
  cout<<K<<endl;
}