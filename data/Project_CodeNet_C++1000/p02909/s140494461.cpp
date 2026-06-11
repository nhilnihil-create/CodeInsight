#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  vector<string> vec={"Sunny","Cloudy","Rainy","Sunny"};
  string s;
  cin>>s;
  for(ll i=0;i<4;i++) {
    if(s==vec[i]) {
cout<<vec[i+1]<<endl;
      return 0;
    }
  }
}