#include<bits/stdc++.h>
using namespace std;

int main(){
  int64_t a,b,k,eat;
  cin>> a >> b >> k;
  eat=min(a,k);
  a-=eat; k-=eat;
  eat=min(b,k);
  b-=eat; k-=eat;
  cout<< a <<" "<< b <<endl;
}