#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  int ans=0;
  for(int i=1;i<=N;i++){
    if(i%2==1){
      ans++;
    }
  }
  double d=(double)ans/N;
  cout<<d<<endl;
}
