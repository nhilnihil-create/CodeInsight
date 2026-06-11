#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
int main(){
  int n;
  std::cin >> n;



  int mi=100;
  int ma=105;
  while (mi<=n) {
    if(mi<=n && n<=ma){
      std::cout << "1" << '\n';
      return 0;
    }
    mi+=100;
    ma+=105;
  }

  std::cout << "0" << '\n';

  return 0;
}
