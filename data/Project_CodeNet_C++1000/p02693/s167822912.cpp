#include<bits/stdc++.h>
using namespace std;

int main(){
  int k, a, b;
  cin>>k>>a>>b;
  int l=(b/k)*k;
  if(a<=l)
    puts("OK");
    else
      puts("NG");
    }