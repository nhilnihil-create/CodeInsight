#include<bits/stdc++.h>
using namespace std;

int gcd(int n, int m){
  if(n%m==0) return m;
  else return gcd(m, n%m);
}

int main(){
    long long a,b; int g; cin>>a>>b; g = gcd(a, b);
    long long ans = a*b/g;
    cout << ans << endl;
}