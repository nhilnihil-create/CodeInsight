#include <bits/stdc++.h>
using namespace std;

int main() {
  int a=0;
string s;
  cin>>s;
  int n=s.size();
  for(int i=0;i<n;i++){
  if(s.at(i)!=s.at(n-1-i)){a=1;
                           cout<<"No"<<endl;
                          break;}
  }
  
  if(a==0){for(int i=0;i<=(n-3)/2;i++){
  if(s.at(i)!=s.at(((n-3)/2)-i)){a=1;
                                cout<<"No"<<endl;
                                break;}
  }}
  if(a==0){cout<<"Yes"<<endl;}
}
 