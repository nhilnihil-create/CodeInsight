#include<bits/stdc++.h>
#define Vsort(a) sort(a.begin(), a.end())
#define rep(i,n) for(int i = 0; i < (n); i++)
#define Srep(i,a,n) for(int i = (a); i < (n); i++)
#define ll long long
#define P pair<int, int>
using namespace std;

bool prime(int n){
  if (n < 2) return false;
  else if (n == 2) return true;
  else if (n % 2 == 0) return false;
  double sqrtn = sqrt(n);
  for (int i = 3; i <= sqrtn; i += 2){
    if (n % i == 0){
      return false;
    }
  }
  return true;
}

int main(){
  int n, judge = 0;
  cin >> n;
  n -= 1;
  while(judge == 0){
    n++;
    if(prime(n)){
      judge++;
    }
  }
  cout << n << endl;
}
