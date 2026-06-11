#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b;
  cin>>a>>b;
  int ans;
  for(int i=1;i<4;i++){
    if(i!=a&&i!=b){ans=i;break;}
  }
  cout<<ans<<endl;
}