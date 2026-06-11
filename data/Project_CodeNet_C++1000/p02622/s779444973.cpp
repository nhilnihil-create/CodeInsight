#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
using namespace std;
int arr[100000]={0};
int main() {
     string x,y;
     long long a=0,d=0;
  cin>>x>>y;
  for(int i=0;i<x.size();i++){
      if(x[i]!=y[i])
          a++;
  }
  cout<<a;
    }