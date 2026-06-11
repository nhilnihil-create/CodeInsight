#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  double u,s;
  cin>>N;
  if(N%2==0){
    s=N/2;
    cout<<s/N<<endl;
  }
  else {
    u=(N-1)/2;
    cout<<(u+1)/N<<endl;
  }
}