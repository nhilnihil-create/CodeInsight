#include<bits/stdc++.h>
using namespace std;

int main(){
  int A,B,C;
  cin>>A>>B>>C;
  int ans=max(0,C-(A-B));
  cout<<ans<<endl;
}