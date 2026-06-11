#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string s;
  cin  >> s;
  vector<int> vec(26);
  rep(i,4){
    int x=s[i]-'A';
    vec[x]++;

  }
  rep(i,26){
    if(vec[i]!=2&&vec[i]!=0){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}