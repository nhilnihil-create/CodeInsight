#include<bits/stdc++.h>
using namespace std;
using ll=long long;



int main(){
  ll H,count=1,kaisu=0;
  cin>>H;
  while(H>=1){
    H/=2;
    kaisu=pow(2,count)-1;
    count++;
  }
  cout<<kaisu<<endl;
}