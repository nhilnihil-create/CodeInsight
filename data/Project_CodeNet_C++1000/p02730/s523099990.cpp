#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

bool isPalindrome(string str){
  bool palindrome = true;
  for(int i = 0; i < str.size(); i++){
    if (str.at(i) != str.at(str.size() - i - 1)) palindrome = false;
  }

  return palindrome;
}

int main(){
  string S;
  cin >> S;

  string left = S.substr(0, (S.size() - 1) / 2);
  string right = S.substr((S.size() + 3) / 2 - 1);
  
  if (isPalindrome(S) && isPalindrome(left) && isPalindrome(right)){
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
  
}