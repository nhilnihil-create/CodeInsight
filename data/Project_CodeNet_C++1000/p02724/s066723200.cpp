#include<bits/stdc++.h>
using namespace std;
int main(){
  int a;
  cin >> a;
  int k=a/500;
  int no=a%500;
  int k2=no/5;
  cout << k*1000+k2*5 << endl;
}