#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
#include <vector>

using namespace std;

int main(){

  int n;
  cin >> n;
  int* x = new int[n];
  for(int i=0;i<n;i++){
    cin >> x[i];
  }

  int m=1;
  int count=1;
  while(true){
    m = m*2;
    if(m>n/2) break;
    count++;
  }
  int* g = new int[count];
  int gi = 1;
  g[0] = gi;
  for(int i=1;i<count;i++){
    gi *= 2;
    g[i] = gi;
  }

  m = count;
  count = 0;
  for(int i=0;i<m;i++){
    for(int j=g[m-1-i];j<n;j++){
      int v = x[j];
      int k = j - g[m-1-i];
      while( k>=0 && x[k] > v){
        x[k+g[m-1-i]] = x[k];
        k = k - g[m-1-i];
        count++;
      }
      x[k+g[m-1-i]] = v;
    }
  }

  cout << m << endl;
  for(int i=0;i<m;i++){
    cout << g[m-1-i];
    if(i == m-1 ) cout << endl;
    else cout << " ";
  }
  cout << count << endl;
  for(int i=0;i<n;i++){
    cout << x[i] << endl;
  }

}

