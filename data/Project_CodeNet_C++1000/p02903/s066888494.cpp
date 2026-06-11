#include <bits/stdc++.h>
using namespace std;

int main(){
  int H,W,min_row,min_col;
  cin >> H >> W >> min_row >> min_col;

  string pattern0,pattern1;
  for(int w=0; w<W; w++){
    if(w < min_row){
      pattern0+= '0';
      pattern1+= '1';
    }
    else{
      pattern0+= '1';
      pattern1+= '0';
    }
  }

  for(int h=0; h<H; h++){
    if(h < min_col){
      cout << pattern0 << endl;
    }
    else{
      cout << pattern1 << endl;
    }
  }
}