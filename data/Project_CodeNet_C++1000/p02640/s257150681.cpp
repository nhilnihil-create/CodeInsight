#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
ll X,Y;
  cin>>X>>Y;
  if(Y%2!=0) {
cout<<"No"<<endl;
  return 0;
  }
  else if(Y>=2*X&&Y<=4*X) {
cout<<"Yes"<<endl;
  }
  else {
cout<<"No"<<endl;
  }
}
