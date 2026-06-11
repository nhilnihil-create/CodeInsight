#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,ans=0;
  cin >> a >> b;
  if(a==3)ans+=100000;
  else if(a==2)ans+=200000;
  else if(a==1)ans+=300000;
  else ans+=0;
  if(b==3)ans+=100000;
  else if(b==2)ans+=200000;
  else if(b==1)ans+=300000;
  else ans+=0;
  if(a==1 && b==1)ans+=400000;
  cout << ans << endl;
}
