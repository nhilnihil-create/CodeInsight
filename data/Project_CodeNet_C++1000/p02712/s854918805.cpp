#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t n;
  cin>>n;
  int64_t x=0;
  for(int i=1;i<=n;i++){
    if(i%3!=0&&i%5!=0){
      x+=i;}
  }
    cout<<x<<endl;
}