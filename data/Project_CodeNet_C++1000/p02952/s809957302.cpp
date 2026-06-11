#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  
 int count =0;
  for(int i=1;i<N+1;i++){
    if(i<10){
      count++;
    }else if(i<100){
      count=count;
    }else if(i<1000){
      count++;
    }else if(i<10000){
      count=count;
    }else if(i<100000){
      count++;
    }
  }
  cout << count <<endl;
}