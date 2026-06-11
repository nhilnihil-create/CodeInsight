#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B;
  cin>>A>>B;
  int sum=-1;
  for(int i=1;i<1500;i++){
    int a=i*0.08;
    int b=i*0.1;
    if(a==A&&b==B){
      sum=i;
      break;
    }
  }
  cout<<sum<<endl;
}