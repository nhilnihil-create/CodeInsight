#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  int m;
  cin>>n;
  if(n % 2 == 0){
    m = n/2;
  }
  else{
    m = n/2+1;
  }
  cout<<(double)m/n<<'\n';
}