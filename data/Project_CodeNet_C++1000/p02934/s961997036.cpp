#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
double sum = 0.0;
  cin>>n;
  double a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
    }
  for(int i=0;i<n;i++){
    sum = sum + (1/a[i]);
    }
  cout<<1/sum<<endl;
  }
 
 