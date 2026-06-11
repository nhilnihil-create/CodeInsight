#include<iostream>
#include<algorithm>

int main(void){
  long long n;
  std::cin >> n;

  std::string ans = "";

  while(n){
    n--;
    ans  += (char)('a' + (n % 26));
    n /= 26;
  }

  std::reverse(ans.begin(), ans.end());

  std::cout << ans << std::endl;

  return 0;

}