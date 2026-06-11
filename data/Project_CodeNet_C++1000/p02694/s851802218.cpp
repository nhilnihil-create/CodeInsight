#include <bits/stdc++.h>
using namespace std;

int main()
{
  long X,sum=100,i=0;
  cin >> X;
  while(sum<X){
    sum+=sum/100;
    i++;
  }
  cout << i;
    }
