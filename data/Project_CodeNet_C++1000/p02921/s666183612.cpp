#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n=0; char s[3],t[3];
  for(int i=0;i<3;i++)cin>>s[i];
  for(int i=0;i<3;i++)cin>>t[i];
  for(int i=0;i<3;i++) if(s[i]==t[i]) n++;
  cout<<n<<endl;
}