#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
  if(a%b == 0) return b;
  return gcd(b,a%b);
}

int main(){
  int N,M;
  cin >> N >> M;
  vector<int> a(N);
  long long ac = 1;
  int two = 0;
  bool flag = true;
  for(int i = 0; i < N; i++){
    int a;
    cin >> a;
    ac = ac*a/2/gcd(ac,a/2);
    int c = 0;
    while(a%2 == 0){
      a /= 2;
      c += 1;
    }
    if(i == 0) two = c;
    else if(two != c) flag = false;
  }
  if(flag) cout << (M/ac)/2+(M/ac)%2 << endl;
  else cout << 0 << endl;
}
