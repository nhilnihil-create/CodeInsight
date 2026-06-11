#include "bits/stdc++.h"
using namespace std;

int main(){
  
  int H,W,K;
  string* c;
  cin >> H >> W >> K;
  c = new string[H];
  for(int i=0;i<H;i++)
    cin >> c[i];
  
  int result = 0;
  for(int hbit=0;hbit<(1<<H);hbit++){
    for(int wbit=0;wbit<(1<<W);wbit++){
      
      int sum=0;
      for(int i=0;i<H;i++){
        if((1<<i)&hbit)
          continue;
        for(int j=0;j<W;j++){
          if((1<<j)&wbit)
            continue;
          else if(c[i].at(j) == '#')
            sum++;
        }
      }
      
      if(sum == K)
        result++;
    }
  }
  
  cout << result;
  delete[] c;
  return 0;
}