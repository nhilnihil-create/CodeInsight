#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  vector<char>vec(4);
  for(ll i=0;i<4;i++){
    cin>>vec.at(i);
  }
  sort(vec.begin(),vec.end());
  if(vec.at(0)==vec.at(1)&&vec.at(2)==vec.at(3)&&vec.at(1)!=vec.at(2)){
    cout<<"Yes"<<endl;
    return 0;
  }
  cout<<"No"<<endl;
}
