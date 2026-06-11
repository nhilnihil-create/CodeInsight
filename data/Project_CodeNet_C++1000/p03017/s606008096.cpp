#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,Ss,Sf,Gs,Gf;
  cin >> N >> Ss >> Sf >> Gs >> Gf;
  vector<bool>a(N);
  char s;
  Ss--,Sf--,Gs--,Gf--;
  for(int i=0;i<N;i++){
    cin >> s;
    a.at(i)=(s=='#');
  }
  bool ans=true;
  for(int i=Ss;i<Gs-1;i++)
    if(a.at(i)&&a.at(i+1))
      ans=false;
  for(int i=Sf;i<Gf-1;i++)
    if(a.at(i)&&a.at(i+1))
      ans=false;
  if(Gs>Sf&&Gf<Gs){
    bool ok=false;
    for(int i=Sf;i<=Gf;i++)
      if(!(a.at(i-1)||a.at(i)||a.at(i+1)))
        ok=true;
    if(!ok)
      ans=false;
  }
  cout << (ans?"Yes":"No") << endl;
  return 0;
}