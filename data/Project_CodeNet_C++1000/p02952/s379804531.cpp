#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,count=0;
  cin >> N;
  for(int i=0;i<N;i++){
    int A=log10(i+1)+1;
    if(A%2==1){
      count++;
    }
  }
  cout << count << endl;
} 