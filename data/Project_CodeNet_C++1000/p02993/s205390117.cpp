#include <bits/stdc++.h>
using namespace std;
typedef int64_t i64;

int main()
{
  string S;
  cin >> S;

  if(S.at(0) == S.at(1) || S.at(1) == S.at(2) || S.at(2) == S.at(3)){
      cout << "Bad" << endl;
  }else{
      cout << "Good" << endl;
  }
}
