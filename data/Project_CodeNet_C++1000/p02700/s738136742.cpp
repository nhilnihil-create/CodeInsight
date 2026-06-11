#include<bits/stdc++.h>
using namespace std;
int main(void){
  int a,b,c,d;cin>>a>>b>>c>>d;
  int x=(a+d-1)/d;
  int y=(c+b-1)/b;
  if(x<y) cout<<"No"<<endl;
  else cout<<"Yes"<<endl;
  return 0;
}
