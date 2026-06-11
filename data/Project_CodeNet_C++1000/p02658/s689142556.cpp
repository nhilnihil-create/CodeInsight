#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
using namespace std;
 
int main() {
  int n;
  unsigned long long a[100000];
  unsigned long long dot[100001]; 
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> a[i] ;
  }

  dot[0] = 1;
  unsigned long long d;
  d = sqrt(1000000000000000000);
  
  sort(a,a+n);
  if(a[0] == 0){
        cout << "0" << endl;
        return 0;  
  }
  
  sort(a,a+n,greater<int>());
  if(a[1] > d){
        cout << "-1" << endl;
        return 0;    
  }

  for(int i = 0; i < n; i++){
    dot[i+1] = (dot[i] * a[i]) ;
    if(dot[i+1] > 1000000000000000000){
        cout << "-1" << endl;
        return 0;
    }
  }
 
  cout << dot[n] << endl;

}
