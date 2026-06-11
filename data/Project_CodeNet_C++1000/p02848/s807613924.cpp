#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using vll = vector<ll> ;
#define all(v) v.begin(),v.end()

int main(){
  int n;cin>>n;
  string s;cin>>s;
  rep(i,s.size()){
    s[i] = 'A' + (s[i]-'A'+n)%26;
  }
  cout<<s<<endl;
}