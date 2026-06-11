#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  long long int X;
  long long int a = 100;
  long long int sum = 0;
  cin>>X;
  while(a < X){
    a += (a/100);
    sum += 1;
  }
  cout<<sum<<'\n'; 
}