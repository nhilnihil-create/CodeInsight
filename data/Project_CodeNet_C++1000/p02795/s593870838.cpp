#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int G,R,N;
  cin >> G >> R >> N;
  
  int count=0;
  int sum=0;
  
  for(int i=0; i < N;i++){
    
    if(G >= R){
      sum += G;
        count++;
      if(sum >= N){
        break;
      }
    }
    
    else if(G < R){
      sum += R;
        count++;
      if(sum >= N){
        break;
      }
    }
    
  }
      cout << count << endl;
	return 0;
      
}

