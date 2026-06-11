#include<bits/stdc++.h>
using namespace std;

int main(){
  long long int x;
  cin>>x;
  long long int a=0;
  long long int count=100;
  while(count<x){
    count+=count/100;
    a++;
  }
  cout<<a<<endl;
}