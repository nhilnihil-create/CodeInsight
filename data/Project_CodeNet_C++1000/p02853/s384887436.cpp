#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> standings(2);int ans=0;
  cin>>standings[0]>>standings[1];
  for(auto it=standings.begin();it!=standings.end();it++){
    int num = *it;
  	if(num<=3){
      ans += (4-num) * 100000;
    }
  }
  if(ans==600000)ans += 400000;
  cout<<ans<<endl;
}
