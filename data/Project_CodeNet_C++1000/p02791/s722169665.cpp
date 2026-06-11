#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const float pi = 3.1415926535;
unsigned GetDigit(unsigned num){
    return to_string(num).length();
}

int main() {
  int n,ans=0;
  cin >> n;
  vector<int>p(n+1);
  vector<int>l_min(n+1);
  for (int i = 0; i < n; i++) {
    cin >> p.at(i);
  }
  
  l_min.at(0) = p.at(0);

  for (int i = 1; i < n; i++) {
    l_min.at(i) = min(l_min.at(i-1),p.at(i-1));
    if (l_min.at(i) >= p.at(i)) {
      ans++;
    }
  }
  ans++; 
  cout << ans << endl;
}