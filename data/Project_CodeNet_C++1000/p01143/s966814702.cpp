#include <iostream>
using namespace std;
#define rep(i,n) for(int i = 1 ; i <= n ; i++)

int main(){
  while(true){
    int n, m, p;
    cin >> n >> m >> p;
    if(n == 0 && m == 0 && p == 0)break;
    int x;
    int hito = 0, sum = 0;;
    
    
    rep(i, n){
      cin >> x;
      sum += x;
      if(i == m){
	hito = x;
      }
    }
    if(hito == 0){
      cout << 0 << '\n';
    }else{
      cout << sum*(100-p)/hito << '\n';
    }
  }
}