#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n;
  cin>>n;
  long long x=100;
  long long count=0;
  while(n>x){
    x+=x/100;
    count++;
  }
  cout<<count<<endl;
  return 0;
}