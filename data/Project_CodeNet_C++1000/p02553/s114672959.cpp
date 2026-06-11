#include<bits/stdc++.h>

int main(){
  long long a, b, c, d; std::cin >> a >> b >> c >> d;
  long long ans = std::max({a*c, a*d, b*c, b*d});
  std::cout << ans;
}
