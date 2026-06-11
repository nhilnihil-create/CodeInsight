#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main() {
  string s;
  cin>>s;
  if(s.at(0)==s.at(1)
     ||s.at(1)==s.at(2)
     ||s.at(2)==s.at(3)){
    cout<<"Bad";
  }
  else{cout<<"Good";}
}

