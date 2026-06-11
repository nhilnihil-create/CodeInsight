#include <bits/stdc++.h>

using namespace std;

int main()
{
  string s[3] = {"Sunny", "Cloudy", "Rainy"};
  string t; cin >> t;
  for(int i = 0; i < 3; i++)
    if(t == s[i])
      return !(cout << s[(i+1)%3] << endl);
}