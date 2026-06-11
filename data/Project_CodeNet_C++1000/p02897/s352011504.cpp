#include<iostream>
using namespace std;
int main(){
  int n;
  cin>>n;
  if(n%2==0)
    cout<<fixed<<(double)n/2/n;
  else if(n%2!=0)
    cout<<fixed<<(double)((n/2)+1)/n;
}