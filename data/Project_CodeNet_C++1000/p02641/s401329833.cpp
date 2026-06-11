#include <bits/stdc++.h>
using namespace std;

int main(){
  int X,N;
  cin >> X >> N;
  
  map<int, int> z;
 
  
  for(int i = 0; i < N; i++){
    int j;
    cin >> j;
    z[j] = j;
  }
  int ans = 10000;
  int i = 0;
  while(ans == 10000){
    if(!(z.count(X-i))){
      ans = X - i;}
    else if (!(z.count(X+i))){
      ans = X + i;
    }
    i++;
  }
  cout << ans << endl;
}
      
    
    

  