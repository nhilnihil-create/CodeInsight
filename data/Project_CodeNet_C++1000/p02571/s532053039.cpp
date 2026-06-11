#include <iostream>

using namespace std;

int main(){
  cin.tie(0); 
  ios::sync_with_stdio(false);
  
  string S,T;
  int cnt,bcnt;
  cnt = 0;
  bcnt = 1000;
  cin >> S >> T;

  int tmp = S.size() - T.size() + 1;
  
  for(int i=0;i<tmp;i++){
    cnt = 0;
    for(int j=0;T[j]!='\0';j++){
      if(S[i+j] != T[j]){
        cnt++;
      }
    }
    if( bcnt > cnt ){
    	bcnt = cnt;
    }
  }
  cout << bcnt << endl;
  
  return 0;
}