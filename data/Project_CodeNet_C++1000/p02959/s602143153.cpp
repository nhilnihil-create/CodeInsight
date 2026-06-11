#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<long long>mon(n+1);
  vector<long long>bre(n);
  for(int i=0;i<n+1;i++)
    cin >> mon.at(i);
  for(int i=0;i<n;i++)
    cin >> bre.at(i);
  long long ans=0,moti=0;
  for(int i=0;i<n;i++){
    if(mon.at(i)<bre.at(i)+moti){
      ans+=mon.at(i);
      moti=bre.at(i)-max(0ll,mon.at(i)-moti);
    }else{
      ans+=bre.at(i)+moti;
      moti=0;
    }
  }
  if(moti>0){
    ans+=min(moti,mon.at(n));
  }
  cout << ans << endl;
  return 0;
}