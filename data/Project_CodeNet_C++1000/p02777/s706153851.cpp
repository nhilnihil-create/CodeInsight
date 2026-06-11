#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main() {
 string s,t;
  int a,b;
  cin>>s>>t>>a>>b;
  string u;
  cin>>u;
  if(s==u){
    cout<<a-1<<' '<<b<<endl;
  }
  else if(t==u){
    cout<<a<<' '<<b-1<<endl;
  }
}
