#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main(){
  ll A,V,B,W,T;
  cin>>A>>V>>B>>W>>T;
  if(abs(A-B) <= abs(V*T) - abs(W*T)){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
}
