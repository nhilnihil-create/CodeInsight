#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a,long long b){
  if(a%b==0)
    return(b);
  else
    return(gcd(b,a%b));
}

int main(){
  long long n,m;
  cin >> n >> m;
  cout << n*m/gcd(n,m) << endl;
}