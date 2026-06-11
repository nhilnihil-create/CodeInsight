#include <bits/stdc++.h>
using namespace std;
bool end(int n,int m){
return n!=m;
}
int main() {
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  cout << end(a,c) << endl;
}  