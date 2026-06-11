#include <bits/stdc++.h>
using namespace std;
 
int n;

int main(){
  cin >> n;
  int a[n];
  for(int i = 0; i < n; ++i){
    cin >> a[i];
  }
  sort(a,a+n);
  cout << (a[n/2] - a[n/2 - 1]) << endl;
}