#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, r = 0, sum = 0;
  cin >> n;
  for(int i=0; n>1000*i; i++){
  	sum = i;
  }
  sum += 1;
  r = 1000*sum - n;
  cout << r << endl;
}