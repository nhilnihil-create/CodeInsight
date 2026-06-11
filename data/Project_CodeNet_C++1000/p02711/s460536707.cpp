#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  string s;
  cin>>s;
  rep(i,3){
    if(s.at(i)=='7'){
      cout<<"Yes"<<endl;
      return 0;
    }
  }
  cout<<"No"<<endl;
}