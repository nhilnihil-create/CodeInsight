#include<bits/stdc++.h>
using namespace std;
int main(){
  long K;cin>>K;
  long p=9;vector<vector<long>>D;
  D.push_back({1,2,3,4,5,6,7,8,9});
  while(p<K){
    vector<long>E;
    for(long x:D[D.size()-1]){
      if(x%10<9)E.push_back(x*10+(x%10)+1);
      E.push_back(x*10+(x%10));
      if(x%10>0)E.push_back(x*10+(x%10)-1);
    }
    sort(E.begin(),E.end());
    D.push_back(E);
    p+=E.size();
  }
  cout<<D[D.size()-1][D[D.size()-1].size()-p+K-1];
}