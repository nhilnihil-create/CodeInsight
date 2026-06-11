#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<string>
#include<sstream>
#include<cmath>
#include<numeric>
using namespace std;

int main(){

  vector<int> a(101);
  int tmp;
  while(cin >> tmp){
    a[tmp]++;
  }
  int ans = *max_element(a.begin(), a.end());
  for(int i=0; i<101; i++){
    if( a[i] == ans ) cout << i << endl;
  }

  return 0;
}