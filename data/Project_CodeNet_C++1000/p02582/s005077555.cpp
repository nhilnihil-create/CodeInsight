#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  int ans=-1;
  if(s=="RRR") ans=3;
  if(s=="RRS"||s=="SRR") ans=2;
  if(s=="RSS"||s=="SRS"||s=="SSR"||s=="RSR") ans=1;
  if(s=="SSS") ans=0;
  cout << ans << endl;
}
