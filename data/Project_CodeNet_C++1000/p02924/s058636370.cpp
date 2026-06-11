#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
//int l[n+1];
int main() {
  int n;
  cin >> n;
  long long res = 0;
  for(int i=1;i<n;i++){
   res += i; 
  }
  
  cout << res;
  
}
