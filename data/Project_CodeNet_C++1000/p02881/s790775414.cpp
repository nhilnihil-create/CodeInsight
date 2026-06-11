#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N;
  cin >> N;
  int64_t a, b, ans;
  
  for(int i=1; i<=sqrt(N)+1; i++){
    if(N%i==0)a=i;
  }
  
  b=N/a;
  ans = a+b-2;
  
  cout << ans << endl;
}