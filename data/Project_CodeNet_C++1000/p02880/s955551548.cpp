#include<bits/stdc++.h>
using namespace std;

int main(){
  long long int N ,ans = 0 ;
  string S ;
  cin >> N ;
  for(int i = 1; i < 10; i++){
    if(N % i == 0 && N / i > 0 && N / i < 10) ans++;
  }
  if(ans > 0) cout << "Yes" <<endl;
  else cout << "No" << endl;
}
