#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  double A,B;
  cin>>A>>B;
  double K=(A+B)/2;
  if(ceil(K)!=floor(K)){
    cout<<"IMPOSSIBLE"<<endl;
  }
  else{
    cout<<(int)K<<endl;
  }
}