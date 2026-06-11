#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,m;
  cin >> a >> b >> m;
  vector<int>an(a);
  vector<int>bn(b);
  vector<tuple<int,int,int>>mn(m,tuple<int,int,int>(0,0,0));
  for(int i=0;i<a;i++)
    cin >> an.at(i);
  for(int i=0;i<b;i++)
    cin >> bn.at(i);
  for(int i=0;i<m;i++)
    cin >> get<0>(mn.at(i)) >> get<1>(mn.at(i)) >> get<2>(mn.at(i));
  int ans=2e5;
  for(int i=0;i<m;i++){
    ans=min(ans,an.at(get<0>(mn.at(i))-1)+bn.at(get<1>(mn.at(i))-1)-get<2>(mn.at(i)));
  }
  sort(an.begin(),an.end());
  sort(bn.begin(),bn.end());
  ans=min(ans,an.at(0)+bn.at(0));
  cout << ans << endl;
  return 0;
}