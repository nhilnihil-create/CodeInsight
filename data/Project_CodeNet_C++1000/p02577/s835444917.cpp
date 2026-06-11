#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<n;i++)
using namespace std;
typedef long long ll;

 
int main() {
  string s;
  cin >> s;
  int co=0;
  
  rep(i,(int)s.size()){
   int a= s.at(i)-'0';
    co+=a;

  }
  
  
  co%=9;
  if(co==0)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  
}