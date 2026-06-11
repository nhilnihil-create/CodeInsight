#include <bits/stdc++.h>
using ll = long long;
using namespace std;
using Graph = vector<vector<ll>>;

int main(){
  string s;
  cin >> s;
  for (size_t i = 0; i < s.length() - 1; i++)
  {
    if (s[i] == s[i+1])
    {
      cout << "Bad" << endl;
      return 0;
    }
    
  }
  cout << "Good" << endl;
  
}