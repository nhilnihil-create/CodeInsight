#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,D;
  cin>>N>>D;
  int a=2*D+1;
  if(N%a==0){
    cout<<N/a<<endl;
  }else{
    cout<<N/a+1<<endl;
  }
}