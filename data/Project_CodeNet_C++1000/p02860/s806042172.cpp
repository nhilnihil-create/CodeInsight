#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  string S;
  cin>>S;
  int s;
  s = S.size();
  if(s%2==1) cout<<"No"<<endl;
  else{
    bool ans=true;
    for(int i=0; i<N/2; i++){
      if(S.at(i)!=S.at(N/2+i)){
        ans=false;
        break;
      }
    }
    if(ans) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
  }
}