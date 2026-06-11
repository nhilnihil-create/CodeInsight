#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N;
  string S;
  cin>>N>>S;
  char x;
  
  rep(i,S.length()){x=S.at(i);
                   x+=N;
                   if(x>90){x-=26;}
                   x=toupper(x);
                   cout<<x;}
  cout<<endl;
}