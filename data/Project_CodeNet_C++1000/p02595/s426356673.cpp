#include <bits/stdc++.h>
using namespace std; 

int main(){
  long long N,D,count=0;
  cin >> N >> D;
  for(long long i=0;i<N;i++){
    long long X,Y;
    cin >> X >> Y;
    if(X*X+Y*Y<=D*D){
      count++;
    }
  }
  cout << count << endl;
}
      
    