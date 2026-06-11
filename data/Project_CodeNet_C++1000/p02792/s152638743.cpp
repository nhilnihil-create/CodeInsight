#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

char area[100][100];
using P=pair<char,bool>;

int main(){
  int n;
  std::cin >> n;
  int v[10][10]={};

  for (int i = 1; i <= n; i++) {

    int b=i%10;
    int t=i;
    while (t/10>0) {
      t/=10;
    }

    v[t][b]++;

    // std::cout << t << ' '<<b%10<<'\n';
  }



  ll ans=0;
  for (int i = 1; i < 10; i++) {
    for (int j = 1; j < 10; j++) {
      // std::cout << i <<':' << j<<' ';
      // std::cout << v[i][j] << '*'<<v[j][i]<<"   " ;
      // std::cout << v[i][j]*v[j][i] << '\n';
      ans+=v[i][j]*v[j][i];
    }
  }

  std::cout << ans << '\n';


  return 0;
}
