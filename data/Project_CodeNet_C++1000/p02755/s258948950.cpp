#include<bits/stdc++.h>
using namespace std;
int main(void){
  int a,b; cin>>a>>b;
  int c=a/0.08,d=b/0.1;
  if(c>d) swap(c,d); --c; ++d;
  while(c<=d){
    if(floor(c*0.08)==a&&floor(c*0.1)==b) break; 
    else ++c;
  }
  if(c>d) cout<<-1; else cout<<c;
  return 0;
}
