#include <bits/stdc++.h>
using namespace std;
int lcm(int a, int b){
  return a/gcd(a,b)*b;
}
int main(void){
    long long int a,b,n,x,i=0,h[200000],ans=0,c=0;
    string s;
    cin >> a >> b;
    cout << lcm(a,b) << endl;
    return 0;
}
