//MISHON69
//DATE:6/22/2020
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  if(n%2==0)
  cout<<fixed<<setprecision(10)<<((double)n/2)/n<<endl;
  else{
     double temp=(n/2)+1;
     cout<<fixed<<setprecision(10)<<temp/n<<endl;
  }
}  
