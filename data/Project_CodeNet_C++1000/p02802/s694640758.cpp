#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,m;	cin >> n >> m;
  vector<bool>	seikai(n+1,false);
  vector<int> p(n+1,0);
  for(int i=0;i<m;i++){
    int po;	string s;	cin >> po >> s;
    if(s=="AC")	seikai.at(po)=true;
    else if(s=="WA"&&seikai.at(po)==false)	p.at(po)+=1;
  }
  
  int ac=0,wc=0;
  for(int i=1;i<=n;i++){
    if(seikai.at(i)){
      ac++;
      wc+=p.at(i);
    }
  }
   cout << ac  << " " << wc;
}