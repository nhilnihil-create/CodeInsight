#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  int a=N%10;
  int b=N%100-a;
  int c=N-b-a;
  if(a==7||b==70||c==700){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}