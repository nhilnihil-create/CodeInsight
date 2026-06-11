#include <bits/stdc++.h>
using namespace std;
int main(){
  long long x;	cin >> x;
  
  long long k=100,y=0;
  while(k<x){
    y++;
    k+=k/100;
  }
  cout << y;
}