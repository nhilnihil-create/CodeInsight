#include <bits/stdc++.h>

int main() {
  std::string s; std::cin >> s;
  int l = s.size();
  std::string rs(s.rbegin(), s.rend());
  bool is_palindrome = true;
  if (s != rs) is_palindrome = false;
  
  std::string sub_s1 = s.substr(0, (l-1)/2);
  std::string sub_rs1 = rs.substr((l+1)/2, (l-1)/2);
  if (sub_s1 != sub_rs1) is_palindrome = false;
  
  std::string sub_s2 = s.substr((l+1)/2, (l-1)/2);
  std::string sub_rs2 = rs.substr(0, (l-1)/2);
  if (sub_s2 != sub_rs2) is_palindrome = false;
  
  if (is_palindrome) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;
  return 0;
}
