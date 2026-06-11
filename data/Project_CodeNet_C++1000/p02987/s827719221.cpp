#include <bits/stdc++.h>
using namespace std;

signed main(){
  set<char>s;
  for(int i=0;i<4;i++){
    char c;cin>>c;s.insert(c);
  }
  cout<<(s.size()==2?"Yes":"No")<<endl;
}
