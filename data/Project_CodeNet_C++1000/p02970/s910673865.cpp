#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b;
  cin >> a >> b;
  cout << ( a % ( 2 * b + 1 ) == 0 ? a / ( 2 * b + 1 ) : a / ( 2 * b + 1 ) + 1 ) << endl;
}