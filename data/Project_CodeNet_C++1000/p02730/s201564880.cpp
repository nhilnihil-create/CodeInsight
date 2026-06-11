#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s)
{
  string t(s.rbegin(), s.rend());
  return s == t;
}

int main()
{
  string S;
  cin >> S;
  
  int N = S.length();
  if(isPalindrome(S) && isPalindrome(S.substr(0, (N-1)/2)) && isPalindrome(S.substr((N+1)/2)))
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
}