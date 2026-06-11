#include<iostream>
using namespace std;

int main(){
  int n;
  cin>>n;
  int x[n+1];

  for (int i=1;i<=n;i++){
    cin>>x[i];
  }
  int sum=1000000;

  for(int v=1;v<=100;v++){
      int k=0; 
    for(int i=1;i<=n;i++){
      k=k+(x[i]-v)*(x[i]-v);
    }
    if(k<sum) sum=k;
  }

  cout<<sum<<endl;
}