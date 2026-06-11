#include <bits/stdc++.h>
using namespace std;

int main(){
 long long N;
  cin >> N;
  
 
  long long sum=0;
  
  for(int i=1;i<=N;i++){
 
    if(i%3==0 || i%5==0){
     continue;
      
    }
    else{
     sum+=i; 
    }
    
  }
  cout << sum << endl;
}