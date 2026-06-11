#include<iostream>
#include<string>
using namespace std;
int main()
{
  int N,D1,D2,count=0,ans=0;
  cin >>N;
  
  for(int i=0; i<N;i++){
    cin >> D1 >> D2;
    if(D1 == D2){
      count++;
    }else{
      count=0;
    }
    if(count==3){
      ans=1;
    }
  }
  
  if(ans==1){
    cout <<"Yes";
  }else{
    cout << "No";
  }
}