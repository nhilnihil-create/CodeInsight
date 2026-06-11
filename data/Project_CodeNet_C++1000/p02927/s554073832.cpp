#include<bits/stdc++.h>
using namespace std ;

int main(){
  int m , d , d1 , d10 , answer ;
  answer = 0 ;
  cin >> m >> d ;
  for(int i=1; i<m+1; i++){
    for(int j=1; j<d+1; j++){
      d1 = j%10 ;
      d10 = j/10 ;
      if(d1>1&&d10>1&i==d1*d10)
        answer++ ;
    }
  }
  cout << answer << endl ;
}