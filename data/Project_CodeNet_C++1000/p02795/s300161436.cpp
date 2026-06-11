#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


int main()
{
  int i,j,k;
  ll H,W,N;
  
  cin >> H;
  cin >> W;
  cin >> N;
  
  if( H<W ){
    if( N%W == 0 ){
      cout << N/W << endl;      
    }
    else{
      cout << N/W+1 << endl;
    }        
  }
  else{
    if( N%H == 0 ){
      cout << N/H << endl;
    }
    else{
      cout << N/H+1 << endl;
    }         
  }
  
  
  
  
  return 0;
}