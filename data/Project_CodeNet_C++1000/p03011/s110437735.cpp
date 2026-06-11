#include <bits/stdc++.h>
using namespace std;
int main(){
  vector<int>time(3);
  for(int i=0;i<3;i++){
    cin>>time.at(i);
  }
  sort(time.begin(),time.end());
  cout<<time.at(0)+time.at(1)<<endl;
}
