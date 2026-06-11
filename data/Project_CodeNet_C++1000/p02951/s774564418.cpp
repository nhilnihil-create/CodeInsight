#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c;
  cin>>a>>b>>c;
  int d=a-b;
  int e=min(d,c);
  int ans=c-e;
  cout<<ans<<endl;
}
