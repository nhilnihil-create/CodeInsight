#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

bool is_palindrome(string s){
  string t(s.rbegin(), s.rend());
  return s == t;
}

int main(void){
  string S;
  cin >> S;

  int N = S.size();
  if (is_palindrome(S) && is_palindrome(S.substr(0, (N - 1) / 2)) && is_palindrome(S.substr((N + 1) / 2))){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }

}
