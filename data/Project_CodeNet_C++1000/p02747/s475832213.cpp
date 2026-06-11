#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
const ll MOD=1000000007;
const long double PI=3.14159265358979;
const ll MAX=0;

int main() {
  string s;
  cin>>s;
  ll c=1;
  for(int i=0;i<s.size();i+=2){
    if(s[i]!='h'||s[i+1]!='i'){
      c=0;
      break;
    }
  }
  if(c){
    cout<<"Yes";
  }
  else{
    cout<<"No";
  }
}
