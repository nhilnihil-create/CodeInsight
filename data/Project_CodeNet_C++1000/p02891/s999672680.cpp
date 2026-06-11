#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
  string s;
  int k;
  cin >> s >> k;

  int flag = 1;
  for (int i = 1; i < s.size(); i++){
    if (s[i] != s[i-1])
      flag = 0;
  }

  if (flag == 1){
    cout << (s.size()*k)/2 << endl;
    return 0;
  }
  int left = 0, right = 0;
  ll ans = 0;

  vector<int> cntr;
  
  while (left < s.size()){
    while ((right+1 < s.size()) && (s[left] == s[right+1])){
      right++;
    }
    int cntrr = right - left + 1;
    cntr.push_back(cntrr);
    ans = ans + cntrr/2;
    left = right + 1;
    right = left;
  }
  
  ans *= k;

  if ((s[0] == s[s.size()-1]) && (cntr[0]%2 == 1 && cntr.back()%2 == 1) && (cntr.size() != 1))
    ans += (k-1);

  cout << ans << endl;
  return 0;
}