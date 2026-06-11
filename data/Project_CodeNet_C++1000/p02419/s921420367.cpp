// Lec09-A Finding a Word
#include<iostream>
#include<string>
#include<algorithm>
int main(){
  static const std::string end = "END_OF_TEXT";
  std::string str1, str2;
  std::cin >> str1;
  int cnt=0, str1_len=str1.length();
  std::transform(str1.begin(), str1.end(), str1.begin(), tolower);
  while(std::cin >> str2){
    if(end == str2) break;
    if(str1_len != str2.length()) continue;
    std::transform(str2.begin(), str2.end(), str2.begin(), tolower);
    if(!str1.compare(0,str1_len,str2,0,str1_len)) cnt++;
  }
  std::cout << cnt << std::endl;
  return 0;
}