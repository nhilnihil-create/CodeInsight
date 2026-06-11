#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin, x.end
#define mkp make_pair
#define trav(x, i) for(auto& i : x)
typedef long long ll;
typedef unsigned int uint;

int main(){
  int a, b;
  cin >> a >> b;
  if(a + b == 3) cout << 3;
  else if (a + b == 5) cout << 1;
  else cout << 2; 
  return 0;
}

