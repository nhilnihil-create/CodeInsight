#include <bits/stdc++.h>
using namespace std;

int main() {
  string N;
  cin >> N;
  if(N[N.size()-1] == '0' || N[N.size()-1] == '1' || N[N.size()-1] == '6' || N[N.size()-1] == '8')cout << "pon" <<endl;
  else if(N[N.size()-1] ==  '3')cout << "bon" <<endl;
  else cout << "hon" <<endl;
}