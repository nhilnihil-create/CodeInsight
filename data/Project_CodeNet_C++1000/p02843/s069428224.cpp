#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n=0;
  cin>>n;
  for(long long i=0;i<n;i++){
    long long test=n-i*100;
    if(0<=test&&test<=5*i){
      cout<<"1"<< endl;
      return 0;
    }
  }
  cout<<"0"<< endl;
}