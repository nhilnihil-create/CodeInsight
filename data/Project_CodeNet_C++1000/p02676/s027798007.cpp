#include <bits/stdc++.h>
using namespace std;

int main()
{
  int k;
  cin >> k;
  
  string s;
  cin >> s;
  
  int n = s.size();
  if(n <=k){
    cout << s << endl;
    return 0;
  }else{
    int i = 0;
    string x = "";
    while(i < k){
      x += s[i];
      i++;
    }
    cout << x << "..." << endl;
  }
}