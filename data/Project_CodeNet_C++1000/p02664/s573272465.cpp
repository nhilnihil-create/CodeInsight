#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i< (n);i++)
using namespace std;

int main() {
  string t;
  cin>>t;
  rep(i,t.size()){
    if(t[i]=='?')t[i]='D';
  }
  cout<<t<<endl;
}
