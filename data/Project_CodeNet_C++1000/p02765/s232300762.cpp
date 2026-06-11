#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
 ll N,R;
  cin>>N>>R;
  if(N>=10) {
cout<<R<<endl;
  }
else {
  cout<<R+100*(10-N) <<endl;
}
}
