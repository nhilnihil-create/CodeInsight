#include<bits/stdc++.h>
using namespace std;
  
int main(){
  int N,K,count=0;
  cin >> N >> K;
  for(int i=0;i<N;i++){
    int H;
    cin >> H;
    if(H>=K){
      count++;
    }
  }
  cout << count << endl;
}