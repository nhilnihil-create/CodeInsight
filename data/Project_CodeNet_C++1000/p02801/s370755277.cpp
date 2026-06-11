#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  char c;
  cin >> c;
  
  vector<char> v={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'}
  rep(i,v.size()){
    if(c == v.at(i))
      cout << v.at(i+1) << endl;
  }
}