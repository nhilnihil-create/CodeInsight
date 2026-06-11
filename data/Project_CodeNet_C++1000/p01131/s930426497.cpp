#include <bits/stdc++.h>
using namespace std;

int main(){
  string p[9]={".,!? ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
  string s;
  int n;
  cin>>n;
  while(n--){
    cin>>s;
    for(int i=0;i<(int)s.size();i++)
      if(s[i]=='0') s[i]=' ';
    stringstream ss(s);
    while(ss>>s){
      cout<<p[s[0]-'1'][(s.size()-1) % p[s[0]-'1'].size()];
    }
    cout<<endl;
  }

  return 0;
}