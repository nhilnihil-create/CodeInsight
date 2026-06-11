#include<iostream>
using namespace std;

int main(){
  int a;
  cin>>a;
  cout<<1000*bool(a%1000)-a%1000<<endl;
}
