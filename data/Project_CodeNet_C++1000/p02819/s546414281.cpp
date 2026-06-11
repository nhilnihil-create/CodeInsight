#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n) ;i++)

using namespace std;
using p=pair<int,int>;
typedef long long ll;

bool is_prime(long long N) {
    if (N == 1) return false;
    for (long long i = 2; i * i <= N; ++i) {
        if (N % i == 0) return false;
    }
    return true;
}

int main() {
  int x;
  cin >> x;
  while(true){
    is_prime(x);
    if(is_prime(x)==true){
      cout << x << endl;
      return 0;
    }
    x++;
  }
  
  return 0;

}
