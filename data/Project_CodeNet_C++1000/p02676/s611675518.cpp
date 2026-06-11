#include <bits/stdc++.h>
 using namespace std;

int main(){
  int K;
  string s;
  cin >> K >> s;
  
  if (s.size() > K)
    cout << s.substr(0,K) << "..." << endl;
  else
    cout << s << endl;

  return 0;
}