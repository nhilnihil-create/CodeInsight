#include<bits/stdc++.h>
using namespace std;
long long lcd(long long a,long long b){
  if(a<b) swap(a,b);
  while(b){
    long long temp = a%b;
    a = b;
    b = temp;
  }
  return a;
}
int main(){
  long long a,b;
  cin>>a>>b;
  cout<<a*b/lcd(a,b);
}