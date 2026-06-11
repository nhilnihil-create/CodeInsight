#include<bits/stdc++.h>
using namespace std;

int main(){
  int A,B;
  cin>>A>>B;
  int sum=1;
  int i=0;
  while(sum<B){
    i++;
    sum+=A-1;
  }
  cout<<i<<endl;
}