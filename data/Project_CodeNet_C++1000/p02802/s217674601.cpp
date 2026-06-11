#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M;
  cin>>N>>M;
  vector<int> p(M);
  vector<string> S(M);
  for(int i=0;i<M;i++){
    cin>>p.at(i);
    p.at(i)--;
    cin>>S.at(i);
  }
  
  vector<int> wa(N),ac(N);
  int ans=0,penalty=0;
  
  for(int i=0;i<M;i++){
    if(S.at(i)=="WA")
      wa.at(p.at(i))++;
    else if(ac.at(p.at(i))==0){
      ac.at(p.at(i))=1;
      ans++;
      penalty += wa.at(p.at(i));
    }
  }
  
  cout<<ans<<" "<<penalty<<endl;
}
