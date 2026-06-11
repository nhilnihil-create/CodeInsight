#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  string N;
  cin >> N;
  
  reverse(N.begin(),N.end());
  if(N.at(0) == '2' || N.at(0) == '4' || N.at(0) == '7' || N.at(0) == '5' ||  N.at(0) == '9'){
    cout << "hon" << endl;
  }else if(N.at(0) == '0' || N.at(0) == '1' || N.at(0) == '6' || N.at(0) == '8'){
    cout << "pon" << endl;
  }else if(N.at(0) == '3'){
    cout << "bon" << endl;
  }
  


}