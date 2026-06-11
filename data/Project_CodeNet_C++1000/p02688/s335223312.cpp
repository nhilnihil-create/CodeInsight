#include<iostream>
#include<vector>

using namespace std;

int main(){
  int N,K;
  cin >> N >> K;
  int d=0;
  int bo;
  int A[N+1];
  for(int i=0;i<K;i++){
    cin >> d;
    //cout << d << " ";
    for(int j=0;j<d;j++){
      cin >> bo;
  	  A[bo] = 1;
    }
  }
  
  int count = 0;
  
  for(int i=1;i<=N;i++){
    //cout << A[i] << endl;
    if(A[i] != 1){
      count++;
    }
  }
  
  cout << count << endl;
}