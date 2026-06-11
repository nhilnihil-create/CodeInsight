#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

template<typename T>
T gcd(T a, T b) {
  if(a < b) swap(a,b);
    
  if(b == 0) return a;
  return gcd(b, a % b);
}

int main(){
  cout << setprecision(10);
  ll A,B; cin >> A >> B;
  ll tmp = gcd(A,B);
  ll C = A / tmp;
  C *= B;
  cout << C << endl;
}
