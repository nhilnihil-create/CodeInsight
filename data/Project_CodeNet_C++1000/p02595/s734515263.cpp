#include<iostream>
using namespace std;
int main(){
  long long int N,D;
  cin >> N >>D;
  long long int X[N];
  long long int Y[N];
  long long int count=0;
  for(int i=0; i<N; i++){
    cin>> X[i] >> Y[i];
  }
  for(int i=0;i<N; i++){
    if(X[i]*X[i]+Y[i]*Y[i] <= D*D){
      count++;
    }
  }
  cout<< count << endl;
}