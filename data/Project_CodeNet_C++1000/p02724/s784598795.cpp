#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int X;
  int sum = 0;
  cin>>X;
  int a = X % 500;
  int b = X - a;
  X = X - b;
  sum += ((b / 500) * 1000);
  int c = a % 5;
  int d = X - c;
  X = X - d;
  sum += ((d / 5) * 5);
  cout<<sum<<'\n'; 
}