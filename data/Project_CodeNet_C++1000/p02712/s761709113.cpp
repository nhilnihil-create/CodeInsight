#include<bits/stdc++.h>
using namespace std;
  
int main(){
  int N;
  long long sum=0;
  cin >> N;
  for(int i=0;i<N;i++){
    if((i+1)%3!=0 && (i+1)%5!=0){
      sum+=i+1;
    }
  }
  cout << sum << endl;
}