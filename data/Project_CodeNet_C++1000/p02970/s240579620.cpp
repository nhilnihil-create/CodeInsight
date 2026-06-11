#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,d;
  cin >> n >> d;
  int a = 2*d+1;
  
  int ans = n/a;
  if(n%a!=0)ans+=1;
  
  cout << ans << endl;
}