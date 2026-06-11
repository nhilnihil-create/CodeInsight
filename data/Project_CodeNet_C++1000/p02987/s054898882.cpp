#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
int main(){
  string s;
  int a[27]={};
  std::cin >> s;
  rep(i,4)a[s[i]-'A']++;
  rep(i,27){
    if(a[i]==0 || a[i]==2);
    else {
      std::cout << "No" << '\n';
      return 0;
    }
  }
  std::cout << "Yes" << '\n';


  return 0;
}
