#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){

  int n; cin >> n;
  long long  mini = 1e+20,maxi=-1e+20,sum=0;
  for(int i=0; i<n; i++){
    long long t; cin >> t;
    mini = min(mini,t);
    maxi = max(maxi,t);
    sum += t;
  }
  cout << mini << " " << maxi << " " << sum << endl;;
}