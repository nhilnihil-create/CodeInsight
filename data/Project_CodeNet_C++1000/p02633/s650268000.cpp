#include<bits/stdc++.h>

using namespace std;

int main(){
  long long x;
  cin>>x;
  
  long long  temp =  ( __gcd( x,( long long ) 360));
  
  cout<< ( (x/temp)*360) /x <<endl;
}
  