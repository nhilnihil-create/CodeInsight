#include <bits/stdc++.h>
using namespace std;
int main(){
  string S;
  cin>>S;
  map<char, int> s;
  for(int i=0; i<4; i++){
    s[S[i]]++;
  }

  /*
  for(pair<char, int>x: s){
    cout<<x.first<<","<<x.second<<endl;
  }
  */
  bool ans = (s.size()==2 && s[S[0]]==2);

  cout<<(ans? "Yes\n": "No\n");
}