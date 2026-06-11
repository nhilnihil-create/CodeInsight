#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;cin>>N;
  map<string,int>mp;
  vector<pair<int,string>>V(0);
  for(int X=0;X<N;X++){
    string S;cin>>S;mp[S]++;
  }
  int D=0;
  for (auto p : mp) {
    auto k=p.first;auto v=p.second;
    V.push_back(make_pair(v,k));
  }
  sort(V.begin(),V.end());
  int U;
  vector<string>VE(0);
  for(int X=V.size()-1;X>=0;X--){
    int C;string D;tie(C,D)=V[X];
    if(X==V.size()-1)U=C;
    else if(C!=U)break;
    VE.push_back(D);
  }
  for(int X=VE.size()-1;X>=0;X--)cout<<VE[X]<<endl;
}