#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
typedef long long ll;

int main(){
  ll a, b, v, w, t;
  cin >> a >> v >> b >> w >> t;
  if(a<b){
    if((b-a) <= t*(v-w)){
        cout << "YES" << endl;
    }
    else{
      cout << "NO" << endl;
    }
  }
  else{
    if((a-b) <= t*(v-w)){
      cout << "YES" << endl;
    }
    else{
      cout << "NO" << endl;
    }
  }
  return 0;
}